#include<stdio.h>
int main()
{
	char str;
	int i, j;
	scanf( "%c", &str );
	for( i = 0; i <= str - 'A'; i++ )
	{ 
		for( j = 0; j < 2 * i + 1; j++ )
			if( j <= str - 'A' )
				printf( "%c ", j + 'A' );
			else
				printf( "%c ", str + i - j );
		printf( "\n" );
	}
	return 0;	
} 
