#include<stdio.h>
int main()
{
	int i, j, n, t, a[100];
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
	{
		scanf ( "%d", &a[i] );
	}
	for ( i = 0; i < n - 1; i++ )
	{
		for ( j = 0; j < n - 1 - i; j++ )
		{
			if ( a[j] < a[j + 1] )
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] % 2 == 0)
		{
			printf ( "%d ", a[i] );
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] % 2 == 1 )
		{
			printf ( "%d ", a[i] );
		}
	}
	return 0;
}
