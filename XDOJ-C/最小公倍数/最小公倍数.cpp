#include <stdio.h>
int main ()
{
	int m, n, i, t;
	scanf ( "%d%d", &m, &n );
	if ( m < n )
	{
		t = m;
		m = n;
		n = t;	
	}
	for ( i = m; i > 0; i++ )
	{
		if ( i % m == 0 && i % n == 0 )
		printf ( "%d\n", i );
		break;
	}
	return 0;
 } 
