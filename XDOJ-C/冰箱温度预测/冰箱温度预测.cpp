#include<stdio.h>
int main()
{
	float h, m, T; 
	scanf ( "%f%f", &h, &m );
	h = h + m / 60;
	T = 4 * h * h / ( h + 2 ) - 20;
	printf ( "%.2f", T );
	return 0;
 } 
