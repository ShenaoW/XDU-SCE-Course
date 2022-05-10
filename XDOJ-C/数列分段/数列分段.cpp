#include <stdio.h>
int main ()
{
	int n, i, s = 1, a[100];
	scanf ( "%d", &n );
	for ( i = 0; i < n; i++ )
		scanf ( "%d", &a[i] );
	for ( i = 0; i < n - 1; i++ )
		if ( a[i] != a[i+1] )
			s++;
	printf ( "%d", s );	
	return 0;
 } 
