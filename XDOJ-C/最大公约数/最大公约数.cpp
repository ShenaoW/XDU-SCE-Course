#include<stdio.h>
int main()
{
	int a, b, min, i;
	scanf ( "%d%d", &a, &b );
	if ( a == 0 && b != 0 )
		printf ( "%d", b);
	else if( a!=0 && b == 0 )
		printf ( "%d", a );
	else
	{
		min = a < b ? a : b;
		for ( i = min; i >= 1; i-- )
			if ( a % i == 0 && b % i == 0 )
				{
					printf ( "%d", i);
					break;
				}
			
	}
	return 0; 
 } 
