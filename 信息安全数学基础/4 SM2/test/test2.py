from Crypto.Util.number import *
'''
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

x,y=multiply(Gx,Gy,k,Gx,Gy)
print(hex(x),hex(y))
'''
import hashlib
import math
# b3 = b'hello'.hex()

#字节串
# print(b3)
# print(type(b3))

#域元素
# b3=int(b3,16)
# print(b3)
# print(type(b3))

#比特串
# b3=bin(b3)
# b3=int(b3,2)
# print(b3+b3)
# print(type(b3))
#
# print(0x10)
# print(type(0x01))

# x=bytes(input(),encoding='UTF-8')
# x=x.hex()
# print(x)
# print(type(x))
#
# x=int(x,16)
# print(x)
# print(type(x))

# h=hashlib.sha256()
# h.update(bytes(input(),encoding='UTF-8'))
# print(h.digest())
# print(type(h.digest()))
#
# print(h.hexdigest())
# print(type(h.hexdigest()))
#
# x=int(h.hexdigest(),16)
# print(size(x))
# print(x)
# print(type(x))

#右移位运算，取左边比特
# print(16>>2)

# print(bin(50587865982489417945093332550836353981949850583218299896239039251790808393741))
# print(size(50587865982489417945093332550836353981949850583218299896239039251790808393741))
# print(bin(50587865982489417945093332550836353981949850583218299896239039251790808393741>>241))
# print(size(50587865982489417945093332550836353981949850583218299896239039251790808393741>>241))
# print(50587865982489417945093332550836353981949850583218299896239039251790808393741>>241)
# print(bin(50587865982489417945093332550836353981949850583218299896239039251790808393741))
# print(bin(14315))

'''
#无穷远点
p=7
a,b=-2,-3
x,y=3,2
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

# print(multiply_point(5,x,y))
# print(inverse(0,7))
'''

# print(bytes(100))
# bytes(str(seq_join(seq,ct)),encoding='UTF8')

# m=int(b'hello world'.hex(),16)
# print(m,type(m))
# print(hex(m))
# M=bytes.fromhex(hex(m)[2:])
# print(M,type(M))

# bug seq_join
# def seq_join(seq1, seq2):    #利用int整型的二进制移位运算进行拼接
#     bitseq = (seq1 << size(seq1)) + seq2
#     return bitseq
# print(bin(seq_join(1,8)))
# print(size(0x10),size(0x02))
# print(bin((8<<1)+1))
# print(bin(seq_join(0b10000001,0b0001)))

# ct=0x00000001
# print(bin(ct)[2:].zfill(32))

print('00001'.zfill(4))