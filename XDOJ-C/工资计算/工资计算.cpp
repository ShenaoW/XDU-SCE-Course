#include<stdio.h>
int main()
{
	int S, A, T, Q;
	scanf ( "%d", &S );
	A = S - 3500;
	if ( A <= 0 )
		Q = 0;
	else if ( A < 1500 )
		Q = A * 0.03;
	else if ( A < 4500 )
		Q = ( A - 1500 ) * 0.1 + 45;
	else if ( A < 9000 )
		Q = ( A - 4500 ) * 0.2 + 345;
	else if ( A < 35000 )
		Q = ( A - 9000 ) * 0.25 + 1245;
	else
		Q = ( A - 35000 ) * 0.3 + 7745;
	T = S - Q;
	printf ( "%d", T );
	return 0;
 } 
