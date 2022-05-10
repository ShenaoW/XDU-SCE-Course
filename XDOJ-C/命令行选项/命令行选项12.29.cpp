#include<stdio.h>
#include<string.h>
int main()
{
	char a[255], b[24] = {0}, t;
	int i, j;
	gets(a);
	for( i = 1; a[i]; i++ )
	{
		if( a[i-1] == '-' )
			b[ a[i]-'a' ] = a[i];
	}
	for( i = 0; i < 23; i++ )
		for( j = 0; j < 23 - i; j++ )
			if( b[j] > b[j+1] )
			{
				t = b[j];
				b[j] = b[j+1];
				b[j+1] = t; 
			}
	for( i = 0; i < 23; i++ )
		if( b[i] != 0 )
			printf( "-%c ", b[i] );	
	return 0;
 } 
