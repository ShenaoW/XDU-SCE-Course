#include<stdio.h>
int main()
{
	char a[100], b[100];
	void fun( char *p1, char *p2 );
	scanf( "%s", a );
	fun( a,b );
	printf( "%s", b );
	return 0;
} 
void fun( char *p1, char *p2 )
{
 	while( *p1 != '\0' )
	{
		*p2 = *p1;
 		p2++;
 		p1 += 2;
 	}
 	*p2 = '\0';
} 
