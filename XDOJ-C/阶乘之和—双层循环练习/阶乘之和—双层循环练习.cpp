#include<stdio.h>
int main()
{
	int i, j, n, mul, sum;
	scanf( "%d", &n );
	for( sum = 0, i = 1; i <= n; i++ )
	{
		mul = 1;
		for( j = 1; j <= i; j++ )
			mul = mul * j;
		sum = sum + mul;
	}
	printf( "%d %d %d", n, mul, sum );	
	return 0;
 } 
