#include<stdio.h>
#include<math.h>
int main()
{
	int prime( int n );
	int i, numb;
	scanf( "%d", &numb );
	for( i = 2; i < numb; i++ )
	{
		if( prime(i) == 1 && prime(numb - i) == 1 )
		{
			printf( "%d %d", i, numb - i );
			break;
		}
	}
	return 0;
 } 
 int prime( int n )
 {
 	int j;
	for( j = 2; j < n; j++ )
		if( n % j == 0 )
			break;
	if( j == n )
		return 1;
	else if( j < n )
		return 0;
 }
