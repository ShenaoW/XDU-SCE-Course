#include<stdio.h>
int main()
{
	int add( int s );
	int n, sum;
	scanf( "%d", &n );
	sum = add( n );
	while( sum >= 10 )
		sum = add( sum );
	printf( "%d", sum ); 
	return 0;
 } 
 int add( int s )
 {
 	int sum = 0;
 	while( s != 0 )
 	{
 		sum = sum + s % 10;
 		s = s / 10;
	 }
	 return sum;
 }
