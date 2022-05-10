#include<stdio.h>
int main()
{
	int n, i;
	scanf ( "%d", &n );
	while ( n != 1 )
	{
		if ( n % 2 == 0 )
			{ 
				n = n / 2;
				i++;
			} 
		else
			{ 
				n = 3 * n + 1;		
				i++;
			} 
	}
	printf ( "%d", i );
	return 0;
 } 
