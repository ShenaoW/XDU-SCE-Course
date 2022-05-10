import math
import hashlib
import binascii
p = 0x8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3
a = 0x787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498
b = 0x63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A
x_G = 0x421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D
y_G = 0x0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2
n = 0x8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7
x_B = 0x435B39CCA8F3B508C1488AFC67BE491A0F7BA07E581A0E4849A5CF70628A7E0A
y_B = 0x75DDBA78F15FEECB4C7895E2C1CDF5FE01DEBB2CDBADF45399CCF77BBA076A42
d_B = 0x1649AB77A00637BD5E2EFE283FBF353534AA7F7CB89463F208DDBC2920BB0DA0

#随机产生1<=k<=n-1
k = 0x4C62EEFD6ECFC2B95B92FD6C3D9575148AFA17425546D49018E5388D49DD7B4F
def ext_gcd(a, b): #扩展欧几里得算法 ，即 a mod b 的逆元,返回的第一个值为结果
    if b == 0:
        return 1,0,a
    else:
        x, y, gcd = ext_gcd(b, a % b) #递归直至余数等于0(需多递归一层用来判断)
        x, y = y, (x - (a // b) * y) #辗转相除法反向推导每层a、b的因子使得gcd(a,b)=ax+by成立
        return x,y,gcd
def sameAdd(x1,y1):
    lamda1 = (3 * (x1 * x1)%p + a)%p
    lamda2 = ext_gcd((2 * y1) % p,p)[0]
    lamda = (lamda1 * lamda2) % p
    x3 = ((lamda * lamda) % p - x1 - x1) % p
    y3 = ((lamda * (x1 - x3)%p) % p - y1) % p
    return x3,y3
def NsameAdd(x1,y1,x_G,y_G):
    lamda1 = (y_G - y1) % p
    lamda2 = ext_gcd((x_G - x1) % p,p)[0]
    lamda = (lamda1 * lamda2) % p
    x3 = ((lamda * lamda) % p - x1 - x_G) % p
    y3 = ((lamda * (x1 - x3)%p) % p - y1) % p
    return x3,y3
def multiply(x1,y1,k,x_G,y_G):
    if k == 2:
        return sameAdd(x1,y1)
    if k == 3:
        x1,y1 = sameAdd(x1,y1)
        return NsameAdd(x1,y1,x_G,y_G)
    if k % 2 == 0:
        x1,y1 = multiply(x1, y1, k // 2,x_G,y_G)
        x1,y1 = sameAdd(x1,y1)
        return x1,y1
    if k % 2 == 1:
        x1,y1 = multiply(x1, y1, (k - 1) // 2,x_G,y_G)
        x1,y1 = sameAdd(x1,y1)
        x1,y1 = NsameAdd(x1,y1,x_G,y_G)
        return x1,y1
def Point_bit(x1,y1):
    X1 = bin(x1)[2:].zfill(256)
    Y1 = bin(y1)[2:].zfill(256)
    return '00000100' + X1 + Y1  #选用未压缩格式
def SHA256(str):
    m = hashlib.sha256()  # 构建sha256对象
    m.update(str.encode(encoding='utf-8'))  # 设置编码格式
    str_sha256 = m.hexdigest()  # hexdigest()将加密字符串 生成十六进制数据字符串值
    return str, str_sha256
def KDF(x,klen):
    ct = 0x00000001
    K = ""
    for i in range(1,klen // 256):  # 调用的SHA256哈希函数，故v = 256
        ct = ct + 1
        K = K + SHA256(x+bin(ct)[2:].zfill(32))[1]
    if klen % 256 != 0:
        K = K + SHA256(x+bin(ct)[2:].zfill(32))[1][:(klen-256*int(klen // 256))//4]
    else:
        K = K + SHA256(x+bin(ct)[2:].zfill(32))[1]

    K = bin(int(K, 16))[2:].zfill(klen) #16进制字符串转2 进制
    return K
def xor(bit_M,t):
    res = ""
    for i in range(len(bit_M)):
        add = int(bit_M[i]) + int(t[i])
        if add == 1:
            res = res + "1"
        else:
            res = res + "0"
    return res
def bit_Point(hexC1):
    #为什么！这么简单的问题那本书上回答的如此晦涩难懂!
    x = int(hexC1[-128:-64], 16)
    y = int(hexC1[-64:], 16)
    if int(hexC1[:2], 16) == 4:
        return x, y
def Point_C1_in(Point_C1):
    x,y = Point_C1
    # y*y=x*x*x+a*x+b 检测方程
    temp1 = y * y % p
    temp2 = (x * x * x + a * x + b) % p
    if temp1 == temp2:
        return 1
    return 0
if __name__=="__main__":
    x1 = x_G
    y1 = y_G
    x2 = x_B
    y2 = y_B
    M_str = b'And now here is my secret, a very simple secret. It is only with the heart that one can see rightly; what is essential is invisible to the eyes. '
    print("明文是： " + str(M_str))
    Q_1 = bytes.hex(M_str)
    M = int(Q_1,16)
    #M = hex(Q_2)
    # print(Q_1)
    # print(Q_3)
    #M = hex(AA)
    # print(type(AA))
    #M = 0x656E6372797074696F6E207374616E64617264 #明文
    x1,y1 = multiply(x1,y1,k,x_G,y_G) #计算椭圆曲线点C1=[k]G=(x1,y1)
    C1_Bit = Point_bit(x1,y1) #将C1数据类型转换为字符串
    #所给公钥一定会满足条件，故未验证
    x2,y2 = multiply(x2,y2,k,x_B,y_B)#计算椭圆曲线点[k]PB=(x2,y2)
    bit_x2 = bin(x2)[2:].zfill(256)
    bit_y2 = bin(y2)[2:].zfill(256)
    # t=KDF(x2||y2,Mlen)  KDF 是密钥派生函数
    bit_M = bin(M)[2:]
    bit_M = (8 - len(bit_M) % 8) * '0' + bit_M
    t = KDF(bit_x2 + bit_y2, len(bit_M))
    C2 = xor(bit_M,t)#计算C2 = M ⊕ t
    C3 = SHA256(bit_x2 + bit_M + bit_y2)# C3=Hash(x2||M||y2)
    hexC1=hex(int(C1_Bit,2))[2:].zfill(130) #拓展到130位
    hexC2 = hex(int(C2, 2))[2:].zfill(len(bit_M) // 4)
    C = hexC1 + hexC2 + C3[1] #生成密文咯！！
    print("密文是： " + str(C))
    #下面进行解密工作
    Point_C1 =  bit_Point(hexC1) #将C1转化为椭圆曲线上的点
    if(1 - Point_C1_in(Point_C1)): #看点是否在椭圆曲线上
        exit("坏了，错了！")
    #无穷远点在这里并没有考虑
    x2,y2 = Point_C1
    x2,y2 = multiply(x2,y2,d_B,Point_C1[0],Point_C1[1]) #计算倍点并转化为2进制数比特串
    bit_x2 = bin(x2)[2:].zfill(256)
    bit_y2 = bin(y2)[2:].zfill(256)
    t = KDF(bit_x2 + bit_y2,len(C2))
    MM = xor(C2,t)  #计算M ′ = C2 ⊕ t
    begin = 0
    MM_ming_bin = ''
    for i in  MM:
        if i == '1':
            begin = 1
        if begin == 1:
            MM_ming_bin += i
    MM_ming = bytes.fromhex(hex(int(MM_ming_bin,2))[2:])
    # print(hex(int(MM_ming,2)))
    print("解密生成的字符串为： " + str(MM_ming))