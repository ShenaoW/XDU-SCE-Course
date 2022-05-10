#include<stdio.h>
int main()
{
	int a[20][20];
	int m, i, j, t, hang[20] = {0}, lie[20] = {0}, zhu = 0, fu = 0, zong[100] = {0};
	scanf( "%d", &m );
	for( i = 0; i < m; i++ )
		for( j = 0; j < m; j++ )
			scanf( "%d", &a[i][j] );
	for( i = 0; i < m; i++ )
	{
		for( j = 0; j < m; j++ )
			hang[i] += a[i][j];
		zong[i] = hang[i];
	}
	for( j = 0; j < m; j++ )
	{
		for( i = 0; i < m; i++ )
			lie[j] += a[i][j];
		zong[m+j] = lie[j];
	}
	for( i = 0; i < m; i++ )
		zhu += a[i][i];
	zong[2*m] = zhu;
	for( i = 0, j = m - 1; i < m && j > -1; i++, j-- )
		fu += a[i][j];
	zong[2*m+1] = fu;
	for( i = 0; i < 2*m; i++ )
		for( j = 0; j < 2*m - i; j++ )
			if( zong[j] < zong[j+1] )
			{
				t = zong[j];
				zong[j] = zong[j+1];
				zong[j+1] = t;
			}
	for( i = 0; i < 2 * m + 1; i++ )
		printf( "%d ", zong[i] );
	printf("\n");	
	return 0;
 } 
