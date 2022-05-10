#include<stdio.h>
#include<string.h> 
int main()
{
	void fun( char *p1, char *p2 );
	char s1[100], s2[100];
	scanf( "%s", s1 );
	scanf( "%s", s2 );
	fun( s1, s2 );
	printf( "%s", s1 );
	return 0;
 } 
void fun( char *p1, char *p2 )
 {
 	int len1 = strlen(p1);
 	while( *p2 != '\0' )
 	{
	 	*( p1 + len1 ) = *( p2 );
 		p1++;
 		p2++;
 	}
 	*( p1 + len1 ) = '\0';
}
 
