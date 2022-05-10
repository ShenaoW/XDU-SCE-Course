#include<stdio.h>
int main()
{
	int a[100][4], b[100][100] = {0};
	int n, i, j, x, y, sum = 0;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		for( j = 0; j < 4; j++ )
			scanf( "%d", &a[i][j] );
	for( i = 0; i < n; i++ )
	{
		for( x = a[i][0]; x < a[i][2]; x++ )
			for( y = a[i][1]; y < a[i][3]; y++ )
				b[x][y] = 1;
	}
	for( x = 0; x < 100; x++ )
		for( y = 0; y < 100; y++ )
			sum += b[x][y];
	printf( "%d", sum );
	return 0;
 } 
