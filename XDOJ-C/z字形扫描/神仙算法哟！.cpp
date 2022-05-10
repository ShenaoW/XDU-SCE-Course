#include<stdio.h>
int main()
{
	int a[100][100];
	int n, nn, i, j;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			scanf( "%d", &a[i][j] );
	for( nn = 0; nn < 2 * n - 1; nn++ )
		if( nn < n )              //打印上三角 
		{
			if( nn % 2 == 0 )     //偶数行从下往上打印 
			{
				i = nn; j = 0;
				while( i >= 0 )
					printf( "%d ", a[i--][j++] ); 
			}
			else                  //奇数行从上往下打印 
			{
				i = 0; j = nn;
				while( j >= 0 )
					printf( "%d ", a[i++][j--] );
			}
		}
		else                      //打印下三角 
		{
			if( nn % 2 == 0)
			{
				i = n - 1; j = nn - n + 1;
				while( j <= n - 1 )
					printf( "%d ", a[i--][j++] );
			}
			else
			{
				i = nn - n + 1; j = n - 1;
				while( i <= n - 1 )
					printf( "%d ", a[i++][j--] );
			}
		}
	return 0;
 } 
