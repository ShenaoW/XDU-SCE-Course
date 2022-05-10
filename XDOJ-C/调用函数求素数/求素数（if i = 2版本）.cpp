#include<stdio.h>
int main()
{
	int fun( int *p, int n );
	int n, i, numb, a[1000];
	scanf( "%d", &n );
	numb = fun( a, n );
	printf( "%d\n", numb );
	for( i = 0; i < numb; i++ )
		printf( "%d ", a[i] );
	return 0;
}
int fun( int *p, int n )
{
	int i, j, numb = 0;
	for( i = 2; i <= n; i++ )
	{
		if( i == 2 )
		{
			*p = i;
			p++;
			numb++;
		}
		else
		{
			for( j = 2; j < i; j++ )
				if( i % j == 0 )
					break;
			if( j == i )
			{
				*p = i;
				p++;
				numb++;
			}
			
			  
		}
	}
	return numb;
}
