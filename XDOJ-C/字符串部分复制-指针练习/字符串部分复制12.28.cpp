#include<stdio.h>
int main()
{
	void copy( char *from, char *to );
	char a[50], b[50];
	char *from = a, *to = b;
	int m;
	gets(a);
	scanf( "%d", &m );
	copy( from + m - 1, to );
	if( b[0] == '\0' )
		printf( "error" );
	else printf( "%s", b );
	return 0;
 } 
 void copy( char *from, char *to )
 {
 	while( *from != '\0' )
 		*(to++) = *(from++);
 	*to = '\0';
 }
