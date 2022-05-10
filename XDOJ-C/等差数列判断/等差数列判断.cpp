#include<stdio.h>
int main()
{
	int a[100];
	int n, i, j, t;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		scanf( "%d", &a[i] );
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
			if( a[j] > a[j+1] )
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	for( i = 0; i < n - 2; i++ )
		if( (a[i+1] - a[i]) != (a[i+2] - a[i+1]) )
			break;
	if( i == n - 2 )
		printf( "%d", a[i+1] - a[i] );
	else
		printf( "no" );	
	return 0;
 } 
