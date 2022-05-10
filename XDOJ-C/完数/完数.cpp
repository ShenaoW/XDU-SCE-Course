#include<stdio.h>
int main()
{
	int a, b, i, j, sum;
	scanf ( "%d%d", &a, &b );
	for( i = a; i <= b; i++ )
		{
		for( j = 1; j < i; j++)
			{
			if  ( i % j == 0 )
				sum = sum + j;
			}
		if ( sum == i )
			printf ( "%d\n", i );
		sum = 0;
		}
	
	return 0;
 } 
