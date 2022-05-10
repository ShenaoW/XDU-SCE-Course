#include<stdio.h>
int main()
{
	char s;
	int i, j;
	scanf( "%c", &s );
	for( i = 0; i <= s - 'A'; i++ )
	{
		for( j = 0; j < s - 'A' - i; j++ )
			printf( " " );
		for( j = 0; j < i; j++ )
			printf( "%c", 'A' + j );
		for( j = i; j >= 0; j-- )
			printf( "%c", 'A' + j );	
		for( j = 0; j < s - 'A' - i; j++ )
			printf( " " );
		if( i < s - 'A' )
			printf( "\n" );
	}
	return 0;
 } 
