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
		if( nn < n )              //��ӡ������ 
		{
			if( nn % 2 == 0 )     //ż���д������ϴ�ӡ 
			{
				i = nn; j = 0;
				while( i >= 0 )
					printf( "%d ", a[i--][j++] ); 
			}
			else                  //�����д������´�ӡ 
			{
				i = 0; j = nn;
				while( j >= 0 )
					printf( "%d ", a[i++][j--] );
			}
		}
		else                      //��ӡ������ 
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
