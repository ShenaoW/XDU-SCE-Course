#include<stdio.h>
int main()
{
	int n,i,d1=0,d2=0,d3=0,d4=0,d5=0,d6=0,a[100];
	float sum=0,ave;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		sum=sum+a[i];
	ave=sum/n;
	printf("%.2f\n",ave);
	for(i=0;i<n;i++)
		{
			if(a[i]<=50)
				d1++;
			else if(a[i]<=100)
				d2++;
			else if(a[i]<=150)
				d3++;
			else if(a[i]<=200)
				d4++;
			else if(a[i]<=300)
				d5++;
			else
				d6++;
		}
	printf("%d %d %d %d %d %d ",d1,d2,d3,d4,d5,d6);
	return 0;
}
