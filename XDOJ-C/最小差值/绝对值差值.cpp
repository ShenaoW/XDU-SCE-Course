#include<stdio.h>
int main()
{
	int n,a[1001],i,j,k,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	  for(j=0;j<n-1;j++)
	  {
	  	if(a[j]>a[j+1])
	  	{k=a[j];
	  	a[j]=a[j+1];
	  	a[j+1]=k;
	  	
	  	}
	  }
	  min=a[1]-a[0];
	  for(i=0;i<n-1;i++)
	  {
	  	if(a[i+1]-a[i]<min)
	  	min=a[i+1]-a[i];
	  	
	  }
	  printf("%d",min);
	  return 0;
}
