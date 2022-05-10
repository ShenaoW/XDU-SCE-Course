#include<stdio.h>
int main()
{
	int n, i, s, a[100]; 
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf ( "%d", &n );
	for ( i = 0; i < n - 2; i++ )
		if ( ( a[i + 1] - a[i]) * ( a[i + 2] - a[i + 1] ) < 0 )
			s = s + 1;
	printf ( "%d", s );
	return 0;
 } 
