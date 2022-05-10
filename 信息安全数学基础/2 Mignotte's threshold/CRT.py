from gmpy2 import *
from Crypto.Util.number import *

def CRT(a_list,m_list):
    m=1
    x=0
    M_list=[]
    M_inv=[]
    for  m_i in m_list:
        m *= mpz(m_i)
    for m_i in m_list:
        M_i=mpz(m//m_i)
        M_list.append(M_i)
        M_inv.append(inverse(M_i,m_i))   #inverse函数直接求逆元
    for i in range(len(m_list)):
        x=mpz(x+M_list[i]*M_inv[i]*a_list[i])
    return mpz(x%m)

# a_list=[2,3,2]
# m_list=[3,5,7]
# print(CRT(a_list,m_list))



