#include<stdio.h>
int main ()
{
	int n, x, i;
	scanf ( "%d", &n );
	x = n * (n - 1) + 1;
	for ( i = 0; i < n; i++ )
	{
		printf ( "%d ", x);
		x = x + 2;
	}
	printf( "\n" );
	return 0;
} 
