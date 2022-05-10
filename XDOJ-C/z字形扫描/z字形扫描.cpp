#include<stdio.h>
int main()
{
	int a[100][100], b[1000] = {0};
	int m, i, j, s = 0;
	scanf( "%d", &m );
	for( i = 0; i < m; i++ )
		for( j = 0; j < m; j++ )
			scanf( "%d", &a[i][j] );
	if( m % 2 == 0 )
	{
		for( i = 0, j = 0; i < m && j < m;)
			if( i == 0 && j % 2 == 0 )
			{
				b[s++] = a[i][j];
				j++;
			}
			else if( i == 0 &&  j % 2 != 0 )
			{
				for( ; j != 0; i++, j-- )
					b[s++] = a[i][j];
			}
			else if( j == 0 && i % 2 != 0  )
			{
				b[s++] = a[i][j];
				i++;
			}
			else if( j == 0 && i % 2 == 0 )
			{
				for( ; i != 0; i--, j++ )
					b[s++] = a[i][j];
			}
			else if( i == m - 1 && j % 2 == 0 )
			{
				b[s++] = a[i][j];
				j++;
			}
			else if( i == m - 1 && j % 2 != 0 )
			{
				for( ; j != m - 1; i--, j++ )
					b[s++] = a[i][j];
			}
			else if( j == m - 1 && i % 2 != 0 )
			{
				b[s++] = a[i][j];
				i++;
			 } 
			 else if( j == m - 1 && i % 2 == 0 )
			 {
			 	for( ; i != m - 1; i++, j-- )
			 		b[s++] = a[i][j];
			 }
		}
		else
		{
			
		}
	 for( i = 0; i < s; i++ )
	 	printf( "%d ", b[i] );
	return 0;
}
