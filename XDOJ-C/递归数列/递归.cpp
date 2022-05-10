#include<stdio.h>
int main()
{
	double function( int n );
	int n; 
	scanf( "%d", &n );
	printf( "%.6f", function(n) );
	return 0;
 } 
 double function( int n )
{
	if ( n == 1 )
		return 1;
	else if ( n != 1 )
		return  1 / ( 1 + function( n - 1 ) ) ;
}
