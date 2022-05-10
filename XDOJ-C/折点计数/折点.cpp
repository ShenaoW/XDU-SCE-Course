#include<stdio.h>
int main()
{
	int a[1001],d=0,i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n-1;i++)
	{
		if(a[i]<a[i-1]&&a[i]<a[i+1])	
	    d++;
		else if(a[i]>a[i+1]&&a[i]>a[i-1])
	    d++;
    }
	printf("%d",d);
	return 0;
}
