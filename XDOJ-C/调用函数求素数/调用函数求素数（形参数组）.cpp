#include<stdio.h>
int main()
{
	int fun( int a[], int n );
	int n, i, numb, a[1000];
	scanf( "%d", &n );
	numb = fun( a, n );
	printf( "%d\n", numb );
	for( i = 0; i < numb; i++ )
		printf( "%d ", a[i] );
	return 0;
}
int fun( int a[], int n )
{
	int i, j, k = 0;
	for( i = 2; i <= n; i++ )
	{
		for( j = 2; j < i; j++ )
			if( i % j == 0 )
				break;
		if( j == i )
			a[k++] = i;
	}
	return k; 
}
