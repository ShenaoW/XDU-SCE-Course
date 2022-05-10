# include<stdio.h>
int main ()
{
	int i, j, t, n, value;
	int a[100];
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		{
			scanf ( "%d", &a[i] );
		}
	for ( i = 0; i < n - 1; i++ )
		for ( j = 0; j < n - 1 - i; j++ )
		{
			if ( a[j] < a[j + 1] )
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	for ( value = a[0] - a[1], i = 1; i < n; i++ )
		{
			if ( value > a[i] - a[i+1] )
				value = a[i] - a[i+1];
		}
	printf ( "%d", value );
	return 0;
}
