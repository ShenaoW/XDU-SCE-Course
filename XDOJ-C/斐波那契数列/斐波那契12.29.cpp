#include<stdio.h>
int main()
{
	int fib(int n);
	int n;
	scanf( "%d", &n );
	printf( "%d", fibs(n) );
	return 0;
 } 
 int fib( int n )
 {
 	if( n == 0 )
 		return 7;
 	else if( n == 1 )
 		return 11;
 	else if( n >= 2 )
 		return fib(n-1) + fib(n-2);
 }
