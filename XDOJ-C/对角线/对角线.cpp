#include <stdio.h>:
int main()
{
int a[3][3], n, i, j, sum1, sum2;
sum1=sum2=0;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
if(i==j)
sum1+=a[i][j];
if(i+j==2)
sum2+=a[i][j];
} 
printf("%d",sum2);
return 0; 
}

