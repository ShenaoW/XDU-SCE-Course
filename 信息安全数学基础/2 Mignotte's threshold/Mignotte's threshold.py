from Crypto.Util.number import *
from re import *
import CRT

#根据秘密 k的二进制位数 len，生成 n个 len/t-1位的素数，作为 Migonotte sequence
def generate_sequence(t,n,k):
    Mig_list=[]
    k_bsize=size(k)          #确定k的二进制位长度，size为 Crypto库中的函数
    gen_bsize=k_bsize//(t-1)     #确定d序列中元素的二进制长度
    while True:
        seq=[]
        seq_re=[]
        while True:
            Mig_list.append(getPrime(gen_bsize))  #生成制定二进制长度的大素数，getPrime为 Crypto库提供的函数
            Mig_list=list(set(Mig_list))          #Mig_list中的元素去重，确保d序列中没有重复元素
            if len(Mig_list)==n:
                break
        # print(Mig_list)

        #正序
        Mig_list.sort()
        for i in range(len(Mig_list)):
            seq.append(Mig_list[i])
        #逆序
        Mig_list.sort(reverse=True)
        for i in range(len(Mig_list)):
            seq_re.append(Mig_list[i])
        # print(seq)
        # print(seq_re)

        #判断是否 M<k<N
        M = 1  # 任意 t-1的 d序列元素的最大乘积
        N = 1  # 任意 t个 d序列元素的最小乘积
        for i in range(t-1):
            M*=seq_re[i]
            N*=seq[i]
        N*=seq[i+1]
        if M<k and k<N:
            print("_____任意t-1项d序列元素的最大乘积M为_____")
            print(M)
            print("_____任意t项d序列元素的最小乘积N为_____")
            print(N)
            print("\n")
            break
        else:
            continue
    return seq

#test generate_sequence
# if check(3,5,10000):
#     print(generate_sequence(3,5,10000))

#根据 Migonotte sequence划分子秘密，返回(k,d)对
def kd_pair(seq,k):
    k_list=[]
    d_list=[]
    for i in seq:
        d_list.append(i)
        k_list.append(k%i)
    return k_list,d_list

#test kd_pair
# print(kd_pair(generate_sequence(3,5,10000),10000))

#根据中国剩余定理进行秘密恢复
def recovery(k_list,d_list):
    k=CRT.CRT(k_list,d_list)
    return k

#test recovery
# kd_list=kd_pair(generate_sequence(3,5,10000),10000)
# k_list=kd_list[0]
# d_list=kd_list[1]
# print(recovery(k_list,d_list))

if __name__ == '__main__':
    print("Please input t,n,k（基于(t,n)门限的秘密k共享）:")
    t,n,k=map(int,split(r'[;,\s]',input()))   #map(int,list)就是将 list内的数据类型转化为 int
    kd_list=kd_pair(generate_sequence(t,n,k),k)
    k_list = kd_list[0]
    d_list=kd_list[1]

    print("_____子秘密k_i分别为_____")
    for i in range(len(k_list)):
        print(k_list[i])

    print("_____Mignotte序列/d序列为_____")
    for i in range(len(d_list)):
        print(d_list[i])
    print("\n")

    print("_____恢复出原秘密为_____")
    print(recovery(k_list,d_list))