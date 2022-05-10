import gmpy2 as gp
import random

def is_prime(num, k):
    for _ in range(k):
        print("第"+str(_+1)+"次素性检测")
        a = random.randrange(2, num - 2)
        print("选取随机数：random="+str(a))
        if gp.gcd(a, num)!=1:
            print("第" + str(_ + 1) + "次素性检测失败，可以判定该数不是素数")
            return False
        if pow(a,num-1,num)!=1:
            print("第" + str(_ + 1) + "次素性检测失败，可以判定该数不是素数")
            return False
        print("第"+str(_+1)+"次检测通过\n")
    return True

n = gp.mpz(input("请输入需要检测的整数n："))
K = int(input("请输入安全参数K："))
boolean=is_prime(n,K)
if boolean:
    print(str(K)+"次素性检测通过，在"+str((1-1/2**K)*100)+"%的概率下可以认为是素数")






