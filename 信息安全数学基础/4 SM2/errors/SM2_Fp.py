import hashlib

import gmpy2 as gp
from Crypto.Util.number import *
from gmssl.sm3 import *

p=0x8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3
a=0x787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498
b=0x63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A
Gx=0x421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D
Gy=0x0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2
n=0x8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7
dB=0x1649AB77A00637BD5E2EFE283FBF353534AA7F7CB89463F208DDBC2920BB0DA0
xb=0x435B39CCA8F3B508C1488AFC67BE491A0F7BA07E581A0E4849A5CF70628A7E0A
yb=0x75DDBA78F15FEECB4C7895E2C1CDF5FE01DEBB2CDBADF45399CCF77BBA076A42
k=0x4C62EEFD6ECFC2B95B92FD6C3D9575148AFA17425546D49018E5388D49DD7B4F

def add_point(x1, y1, x2, y2):    #点加转化为域元素进行运算
    if x1!=x2:
        lamda = ((y2-y1)*inverse((x2-x1),p))%p   #在有限域中，除法运算即求逆！
        x3=((lamda**2)%p-x1-x2)%p
        y3 = ((lamda*(x1-x3))%p-y1)%p
    else:
        lamda = ((3*(x1**2)%p+a)*inverse(2*y1,p))%p
        x3=((lamda**2)%p-2*x1)%p
        y3=(lamda*(x1-x3)%p-y1)%p
    return x3,y3

def multiply_point(k, x1, y1): #倍点运算递归转化为加法运算
    if k == 1:
        return x1, y1
    elif k == 2:
        return add_point(x1, y1, x1, y1)
    elif k % 2 == 0:
        x, y = multiply_point(k // 2, x1, y1)
        x, y = multiply_point(2, x, y)
        return x,y
    elif k % 2 == 1:
        x, y = multiply_point((k - 1) // 2, x1, y1)
        x, y = multiply_point(2, x, y)
        x, y = add_point(x, y, x1, y1)
        return x, y

# multiply_point test
# x,y=multiply_point(k,Gx,Gy)
# print(hex(x),hex(y))
#
# x2,y2=multiply_point(k,xb,yb)
# print(hex(x2),hex(y2))

# 改用字符串拼接
def seq_join(seq1, seq2):    #利用int整型的二进制移位运算进行拼接
    bitseq = (seq1 << size(seq1)) + seq2
    return bitseq

# seq_join test
# b=b'Hello world!'
# b=int(b.hex(),16)
# print(bin(b),len(bin(b)))
# print(bin(seq_join(b,b)),len(bin(seq_join(b,b))))

def KDF(seq,klen):
    # 杂凑算法用sha256
    v=256
    ct=0x00000001
    H=[]
    interation = ceil_div(klen, v)
    #分块产生密钥
    for i in range(0,interation):
        m=hashlib.sha256()
        m.update(bytes(str(seq_join(seq,ct)),encoding='UTF8'))   #将 int转化为 str，再转化为 bytes类型进行 hash
        H.append(int(m.hexdigest(),16))
        size_H=size(int(m.hexdigest(),16))  #哈希值的二进制位长不一定等于256，主要取决于首位
        ct+=1
    #每块密钥进行拼接，最后一块如果不足256位，用左边比特补齐
    k=0
    if klen%v==0:
        for i in range(0,interation):
            k=seq_join(k,H[i])
    else:
        for i in range(0,interation-1):
            k=seq_join(k,H[i])
        H[interation-1]=H[interation-1]>>(size_H-(klen%256))  #在最后 一块补全长度时，需要考虑最后一块的哈希值二进制长度
        k=seq_join(k,H[interation-1])
    #验证密钥生成长度满足预期后再return
    if size(k)==klen:
        return k
    else:
        print("KDF error!")

# KDF test
# print(KDF(12138,size(12138)))

def encrypt(m:bytes):
    m=int(m.hex(),16)
    # print('encrypt:' + str(m))
    k = getRandomRange(1,n)
    C1_x, C1_y = multiply_point(k,Gx,Gy)
    #用未压缩的点到比特串转换，选用未压缩形式
    PC=0x04
    # C1=seq_join(PC,seq_join(C1_x,C1_y))
    # S_x,S_y=multiply_point(h,xb,yb)  无穷远点如何定义？
    x2,y2 = multiply_point(k,xb,yb)
    # print('encrypt:' + str(x2) + str(y2))
    t=KDF(seq_join(x2,y2),size(m))
    C2= m ^ t
    C3_hash=hashlib.sha256()
    C3_hash.update(bytes(str(seq_join(x2,seq_join(m,y2))),encoding='UTF8'))
    C3=int(C3_hash.hexdigest(),16)
    # C=seq_join(C1,seq_join(C2,C3))
    # C=[str(C1),str(C2),str(C3)]
    # print(C)
    return C1_x,C1_y,C2,C3,size(m)
# encrypt test
# print(encrypt(b'hello world'))

def decrypt(C1_x,C1_y,C2,C3,klen):
    if (C1_x**3+(a*C1_x)+b)%p != (C1_y**2)%p:
        print('C1 check error!')
        return False
    else:
        x2,y2=multiply_point(dB,C1_x,C1_y)
        # print('decrypt:'+str(x2)+str(y2))
        t=KDF(seq_join(x2,y2),klen)
        m=C2^t
        # print('decrypt:'+str(m))
        u_hash=hashlib.sha256()
        u_hash.update(bytes(str(seq_join(x2,seq_join(m,y2))),encoding='UTF8'))
        u=int(u_hash.hexdigest(),16)
        if u != C3:
            print('C3 check error!')
            return False
        else:
            M = bytes.fromhex(hex(m)[2:])  # 截取得到 hexstr
            return M

if __name__=="__main__":
    PC = 0x04
    C1_x,C1_y,C2,C3,klen = encrypt(bytes(input(),encoding='UTF8'))
    print('C1:'+bin(seq_join(PC,seq_join(C1_x,C1_y))))
    print('C2:'+bin(C2))
    print('C3:'+bin(C3))
    print(decrypt(C1_x,C1_y,C2,C3,klen))
