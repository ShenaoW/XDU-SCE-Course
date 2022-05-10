#include<stdio.h>
int main()
{
	struct Numb
	{
		int hang;
		int lie;
		int numb;
	} s[100] = {0,0,0};
	int m, n, i, j, x, y, u = 0;
	int a[100][100];
	scanf( "%d%d", &m, &n );
	for( i = 0; i < m; i++ )
		for( j = 0; j < n; j++ )
			scanf( "%d", &a[i][j] );
	for( i = 0; i < m; i++ )
	{
		for( j = 0; j < n; j++ )
		{
			for( x = 0; x < m; x++ )
				if( a[i][j] < a[x][j] )
					break;
			for( y = 0; y < n; y++ )
				if( a[i][j] > a[i][y] )
					break;
			if( x == m && y == n )
			{
				s[u].hang = i;
				s[u].lie = j;
				s[u++].numb = a[i][j];
			}	
		}
	}
	u = 0;
	if( s[0].hang == 0 && s[0].lie == 0 && s[0].numb == 0 )
		printf( "no\n");
	else
		while( s[u].hang != 0 )
			printf("%d %d %d\n", s[u].hang, s[u].lie, s[u++].numb);
	return 0;
 } 
