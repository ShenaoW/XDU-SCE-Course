#include<stdio.h>
int main ()
{
	int n, hun, ten, ind;
	for ( n = 100; n < 1000; n++ )
	{
		hun = n / 100;
		ten = ( n - hun * 100 ) / 10;
		ind = n % 10;
		if ( n == hun * hun * hun + ten * ten * ten + ind * ind * ind )
			printf ( "%d ", n );
	}
	return 0;
 } 
