#include<stdio.h>
int main ()
{
	int n, n1, n2 = 0, s = 0, sum = 0;
	scanf ( "%d", &n );
	n1 = n;
	while( n1 != 0 )
	{
		s = n1 % 10;
		sum = sum + s;
		n2 = n2 * 10 + s;	
		n1 = n1 / 10;
	}
	if( n2 == n )
		printf( "%d", sum );
	else
		printf( "no" );	
	return 0;
 } 
