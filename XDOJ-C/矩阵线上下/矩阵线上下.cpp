#include<stdio.h>
int main()
{
	int a[100][100];
	int i, j, n, flag1 = 0, flag2 = 0;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			scanf( "%d", &a[i][j] );
	for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
		{
			if( i < j && a[i][j] != 0 )
				flag1 = 1;
			if( i > j && a[i][j] != 0 )
				flag2 = 1;
		}
	if( flag1 == 0 && flag2 == 0 )
		printf( "PD" );
	else if( flag1 == 1 && flag2 == 0 )
		printf( "DOWN" );
	else if( flag1 == 0 && flag2 == 1 )
		printf( "UP" );
	else if( flag1 == 1 && flag2 == 1 )
		printf( "NO" );	
	return 0;
 } 
