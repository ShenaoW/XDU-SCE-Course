#include<stdio.h>
int main ()
{
	int n, i, j, t, times = 1;
	int a[100] = {0}; 
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf ( "%d", &a[i] );
	for ( i = 0; i < n - 1; i++ )
		for ( j = 0; j < n - 1 - i; j++ )
			if ( a[j] > a[j+1] )
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	for ( i =0; i < n; i++ )
		{
			if ( a[i] == a[i+1] )
				times = times + 1;
			else
			{
				printf ( "%d:%d\n", a[i], times );
				times = 1;
			}
		}
	return 0;
 } 
