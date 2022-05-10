#include<stdio.h>
#include<string.h>
int main()
{
	char a[9];
	gets(a);
	int b[10],i;
	for(i=0;a[i]!='\0';i++)
	b[i]=a[i]-'0';
	for(int n=0;n<i-1;n++) 
		for(int j=0;j<i-n-1;j++)
		{
			if(b[j]<b[j+1])
			{
				int t=b[j];b[j]=b[j+1];b[j+1]=t; 
			}
		}
	for(int n=0;n<i;n++)
		printf("%d ",b[n]);
 } 
