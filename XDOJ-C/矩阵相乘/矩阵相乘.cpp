#include<stdio.h>
int main ()
{
	int a[2][3], b[3][2], c[2][2], i, j, k, temp;
	for ( i = 0; i < 2; i++ )
		for ( j = 0; j < 3; j++ )
		{
			scanf ( "%d", &a[i][j] );
		}
	for ( i = 0; i < 3; i++ )
		for ( j = 0; j < 2; j++ )
		{
			scanf ( "%d", &b[i][j] );
		}
	for ( i = 0; i < 2; i++ )
		for ( j = 0; j < 2; j++ )
			{
				temp = 0;
				for ( k = 0; k < 3; k++ )
					temp = temp + a[i][k] * b[k][j];
				c[i][j] = temp;
			}
			
	for ( i = 0; i < 2; i++ )
		{
			if ( i >= 1 ) printf ( "\n" );
			for ( j = 0; j < 3; j++ )
				printf ( "%5d", a[i][j] );
		}
	printf ( "\n\n" );
	for ( i = 0; i < 3; i++ )
		{
			if ( i >= 1 ) printf ( "\n" ) ;
			for ( j = 0; j < 2; j++ )
				printf ( "%5d", b[i][j] );
		}
	printf ( "\n\n" );
	for ( i = 0; i < 2; i++ )
		{
			if ( i >= 1 ) printf ( "\n" );
			for ( j = 0; j < 2; j++ )
			printf ( "%5d", c[i][j] );
		}
	return 0;
 } 
