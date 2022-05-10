#include<stdio.h>
int main()
{
	int a[256][256], xs[16] = {0};
	int i, j, n, m;
	scanf( "%d%d", &n, &m );
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
			scanf( "%d", &a[i][j] ); 
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
			xs[a[i][j]]++;
	for( i = 0; i < 16; i++ )
		if(xs[i] != 0 )
			printf( "%d %d\n", i, xs[i] );
	return 0;
}
