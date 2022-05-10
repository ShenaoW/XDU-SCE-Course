#include<stdio.h>
int main()
{
	int n,i,sum = 0,s[10];
	long a,b;
	scanf("%d",&a);
	b = a;
	for(i=0;b!=0;i++)
	{
		s[i]=b%10;
		b=b/10;
		
	}    //求各位数字并存入s数组中 
	n=i;
	for(i=0;i<n;i++)
	{
		if(s[i]==s[n-i-1])    //判断s数组对称位置数字是否相等，也即是否符合回文数条件 
		sum=sum+s[i];
		else
		  break;
	}
	if(i == n)
	printf("%d",sum);
	else
	printf("no");
	return 0;
} 
