#include<stdio.h>
int main()
{
	int i, j, t, k, m, n, sum = 0;
	int a[20][20], quyu[50] = {0};
	scanf( "%d%d%d%d", &n, &m, &t, &k );
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
			scanf( "%d", &a[i][j] );
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
			if( a[i][j] == k )
			{
				if( a[i][j-1] != k && j - 1 >= 0 )
					quyu[a[i][j-1]] = 1;
				if( a[i][j+1] != k && j + 1 < m )
					quyu[a[i][j+1]] = 1;
				if( a[i-1][j] != k && i - 1 >= 0 )
					quyu[a[i-1][j]] = 1;
				if( a[i+1][j] != k && i + 1 < n )
					quyu[a[i+1][j]] = 1;
			}
	for( i = 1; i <= t; i++ )
		sum += quyu[i];	
	printf( "%d", sum );
	return 0;
 } 
