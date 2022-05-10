#include<stdio.h>
#include<string.h>
int main()
{
	void copystr( char *from, char *to, int m );
	char a[100], b[100];
	int m;
	scanf( "%s", a );
	scanf( "%d", &m );
	if( m > strlen(a) )
		printf( "error" );
	else copystr( a, b, m );
	printf( "%s", b );
	return 0;
}
void copystr( char *from, char *to, int m )
{
	while( *(from + m - 1 ) != '\0' )
	{
		*to = *( from + m - 1 );
		to ++;
		from ++;
	}
	*to = '\0';
}
