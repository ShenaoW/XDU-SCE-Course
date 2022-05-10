#include<stdio.h>
#include<math.h>
int main ()
{
	int numb,sq;
	scanf ( "%d", &numb );
	sq = pow ( numb, 0.5 );
	if ( sq * sq == numb )
		printf ( "%d", sq ); 
	else
		printf ( "no" );
	return 0;
 } 
