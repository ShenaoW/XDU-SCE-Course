from Crypto.Util.number import *
'''
for i in range(1,12):
    for j in range(1,12):
        if (j**2)%11 == (i**3+i+6)%11:
            print(i,j)
'''




p=11
a=1
b=6
Gx=2
Gy=7
dB=7

def add_point(x1,y1,x2,y2):    #点加转化为域元素进行运算
    if x1!=x2:
        lamda = ((y2-y1)//(x2-x1))%p
        x3=((lamda**2)%p-x1-x2)%p
        y3 = ((lamda*(x1-x3))%p-y1)%p
    else:
        lamda = ((3*(x1**2)%p+a)*inverse(2*y1,p))%p
        x3=((lamda**2)%p-2*x1)%p
        y3=(lamda*(x1-x3)%p-y1)%p
    return x3,y3

def multiply_point(k,x1,y1): #倍点运算递归转化为加法运算
    x,y=x1,y1
    for i in range(1,k+1):
        x,y=add_point(x,y,x1,y1)
    return x,y
print(multiply_point(2,Gx,Gy))
print(multiply_point(3,Gx,Gy))

PB=multiply_point(dB,Gx,Gy)
