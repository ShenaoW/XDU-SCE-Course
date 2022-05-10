#include<stdio.h>
int main()
{
	int add( int n ); 
	int s;
	scanf( "%d", &s );
	while( add(s) >= 10 )
		s = add(s);
	printf( "%d", add(s) );
	return 0;
 } 
 int add( int n )
 {
 	int sum = 0;
 	while( n != 0 )
 	{
 		sum = sum + n % 10;
 		n /= 10;
	 }
	 return sum;
 }
