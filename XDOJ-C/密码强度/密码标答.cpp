#include<stdio.h>
#include<string.h>
int main()
{
	char a[55];
	int i=0,k1=0,k2=0,k3=0,k4=0,length=0,sum=0;
	gets(a);
		sum=1;
		length=strlen(a);
		if(length==0) sum=0;
		if(length>8) sum++;
		while(a[i]!='\0')
		{
			if(a[i]>='A'&&a[i]<='Z') k1=1;
			else if(a[i]>='a'&&a[i]<='z') k2=1;
			else if(a[i]>='0'&&a[i]<='9') k3=1;
			else k4=1;
			i++;
		}
		if(k1+k2+k3+k4==2) sum=sum+1;
		else if(k1+k2+k3+k4==3) sum=sum+2;
		else if(k1+k2+k3+k4==4) sum=sum+3;
	printf("%d",sum);
} 

