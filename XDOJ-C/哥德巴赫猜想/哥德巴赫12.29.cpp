#include<stdio.h>
int main()
{
	int su( int n );
	int numb, i;
	scanf( "%d", &numb );
	for( i = 2; i < numb; i++ )
		if( su(i) && su(numb-i) )
		{
			printf( "%d %d", i, numb - i );
			break;
		}
	return 0;
 } 
 int su( int n )
 {
 	int i;
 	for( i = 2; i < n; i++ )
 		if( n % i == 0 )
 			break;
 	if( i == n )
 		return 1;
 	else
 		return 0;
 }
