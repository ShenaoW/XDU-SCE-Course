#include<stdio.h>
int main()
{
	int n, i, j, t, u, a[100], b[100], c[100];
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		{
			scanf ( "%d", &a[i] );
			c[i] = a[i];
		}
	for ( i = 0; i < n; i++ )
	{
		while ( a[i] != 0 )
		{
			b[i] += a[i] % 10;
			a[i] = a[i] / 10;
		}
	}
	for ( i = 0; i < n - 1; i++ )
		for ( j = 0; j < n - 1 -i; j++ )
		{
			if ( b[j] < b[j+1] )
			{
				t = c[j]; u = b[j]; 
				c[j] = c[j+1]; b[j] = b[j+1];
				c[j+1] = t; b[j+1] = u;
			}
			else if ( b[j] == b[j+1] )
			{
				if ( c[j] < c[j+1] )
				{
					t = c[j]; u = b[j]; 
					c[j] = c[j+1]; b[j] = b[j+1];
					c[j+1] = t; b[j+1] = u;
				}
			}
		 } 
	printf ( "%d", c[0] );
	return 0;
} 
