#include<stdio.h>
int main() 
{
	int n,i,j,k,t,a[100],b[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		b[i]=a[i]%10+(a[i]/10)%10+(a[i]/100)%10+(a[i]/1000)%10;
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
			if(b[i]<b[i+1])
			{
			t=b[i];k=a[i];
			b[i]=b[i+1];a[i]=a[i+1];
			b[i+1]=t;a[i+1]=k;
			}
			else if(b[i]==b[i+1])
			{
			if(a[i]>a[i+1])
				{
				t=b[i];k=a[i];
				b[i]=b[i+1];a[i]=a[i+1];
				b[i+1]=t;a[i+1]=k;
				}
			}
	
	for(i=0;i<n;i++)
		printf("%d %d\n",a[i],b[i]);
	return 0;
 } 
