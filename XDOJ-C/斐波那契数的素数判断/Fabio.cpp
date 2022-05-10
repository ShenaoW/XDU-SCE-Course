#include<stdio.h>
int main()
{
	int fabio( int n );
	int m, n, i;
	scanf( "%d", &n );
	m = fabio(n);
	for( i = 2; i < m; i++ )
		if( m % i == 0 )
			break;
	if( i == m )
		printf( "yes" );
	else
		printf( "%d", m ); 
	return 0;
}
int fabio( int n )
{
	if( n == 1 || n == 2 )
		return 1;
	else if( n > 2 )
		return fabio( n - 1 ) + fabio( n - 2 );
}
