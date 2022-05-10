import Crypto.Util.number

def check(m,p):
    if m>p:
        return False
    else:
        return True

def find_PrimitiveRoot(p):
    # 对于 p=2q+1形式的强素数，p-1的质因子只有 2，q，p-1
    phi = p - 1
    q = phi // 2
    fac_list = [2,q,phi]
    # 判断 2是否为原根
    for i in range(len(fac_list)):
        if pow(2, phi//fac_list[i], p)==1:
            break
    if i==len(fac_list)-1:
        return 2
    else:
        #判断 q是否为原根
        for i in range(len(fac_list)):
            if pow(q, phi//fac_list[i], p)==1:
                break
        if i==len(fac_list)-1:
            return q
        else:
            return False

#生成 p=2q+1形式的强素数并求其原根
def p_generate(gen_size):
    while True:
        p=Crypto.Util.number.getStrongPrime(gen_size)  #生成强素数 p使得 p-1和 p+1至少有一个大素数因子
        q=(p-1)//2
        # print(p)
        if find_PrimitiveRoot(p):
            g=find_PrimitiveRoot(p)
            break
    return p,q,g

def key(p,g):
    secret_key=Crypto.Util.number.getRandomNBitInteger(4)
    # print(secret_key)
    g_a=pow(g,secret_key)
    public_key=[p,g,g_a]
    return public_key,secret_key

def encrypt(m,public_key):
    p=public_key[0]
    # print(p)
    g=public_key[1]
    g_a=public_key[2]
    k=Crypto.Util.number.getRandomNBitInteger(4)
    C1=pow(g,k,p)
    C2=pow(g_a,k)*m%p
    # test=gp.mpz(pow(g_a,k))*m
    # print(test.bit_length())
    return k,C1,C2

def decrypt(C1,C2,secret_key,public_key):
    p = public_key[0]
    V=pow(C1,secret_key,p)
    V_inv=Crypto.Util.number.inverse(V,p)
    # print("V_inv="+str(V_inv))
    m=C2*V_inv%p
    return m

if __name__ == '__main__':
    #获取明文m
    m=int(input("请输入秘密m："))

    #生成强素数 p并求其原根 g
    p,q,g=p_generate(512)
    print("p的值为："+str(p))
    print("q的值为："+str(q))
    print("g的值为："+str(g))

    if check(m,p):
        #计算公私钥并完成加解密
        public_key, secret_key=key(p,g)
        print("Alice的公钥为："+str(public_key))
        print("Alice的私钥为："+str(secret_key))

        k,C1, C2=encrypt(m,public_key)
        print("Bob选取的随机数k为："+str(k))
        print("密文C1为："+str(C1))
        print("密文C2为："+str(C2))

        m=decrypt(C1,C2,secret_key,public_key)
        print("恢复出秘密为："+str(m))
    else:
        print("m>p,请重新输入m")

