#include<stdio.h>
int main()
{
	struct HAOMA
	{
		int n;
		int sum;
	}a[100], t;
	int i, j, n;
	int sum_n( int n );
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &a[i].n );
		a[i].sum = sum_n( a[i].n );
	}
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
			if( a[j].sum < a[j+1].sum )
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
			if( a[j].sum == a[j+1].sum )
				if( a[j].n < a[j+1].n )
				{
					t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
				}
	printf( "%d", a[0].n );
	return 0;
 } 
 int sum_n( int n )
 {
 	int s = 0;
 	while( n != 0 )
 	{
 		s += n % 10;
 		n /= 10;
	 }
	 return s;
 }
