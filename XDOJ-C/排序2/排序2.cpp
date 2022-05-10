#include<stdio.h>
int main ()
{
	int n, i = 0, j = 0, k = 0, t, a[100], b[100], c[100];
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf ( "%d", &a[i] );
	while ( i < n)
	{
		if ( a[i] % 2 == 0)
		{
			b[j] = a[i];
			j++ ;
			i++ ;	
		}
		else
		{
			c[k] = a[i];
			j++ ;
			k++ ;	
		}
	}
	for( i = 0; i < n - 1; i++ )
		for ( ; j < n -1 -j; j++ )
			if ( b[j] < b[j + 1] )
			{
				t = b[ i ];
				b[ i ] = a[ i + 1 ]; 
				b[ i + 1 ] = t;	
			}
	for( i = 0; i < n - 1; i++ )
		for ( ; j < n -1 -j; j++ )
			if ( c[j] < c[j + 1] )
			{
				t = c[ i ];
				c[ i ] = c[ i + 1 ]; 
				c[ i + 1 ] = t;	
			}
	for ( i = 0; i < n; i++ )
	printf ( "%d ", b[ i ] );
	for ( i = 0; i < n; i++ )
	printf ( "%d ", c[ i ] );
	return 0;
}
