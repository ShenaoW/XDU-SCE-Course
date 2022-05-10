#include<stdio.h>
int main ()
{
	int numb, n;
	scanf("%d",&numb);
	n = numb%10 + (numb/10)%10 + (numb/100)%10 + (numb/1000)%10 + (numb/10000)%10 + (numb/100000)%10 + (numb/1000000)%10 +(numb/10000000)%10 + (numb/100000000)%10;
	printf("%d",n);
	return 0;
 } 
