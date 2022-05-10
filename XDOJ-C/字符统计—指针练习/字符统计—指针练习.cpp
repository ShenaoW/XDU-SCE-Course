#include<stdio.h>
int main()
{
	void count( char *p1, int *p2 );
	char string[100];
	int numb[5] = {0};
	int i;
	gets(string);
	count( string, numb );
	for( i = 0; i < 5; i++ )
		printf( "%d ", numb[i] );
	return 0 ;
 } 
void count( char *p1, int *p2 )
{
	for( ; *p1 != '\0'; p1++ )
	{
		if( *p1 >= 'A' && *p1 <= 'Z' )
			(*p2)++;
		else if( *p1 >= 'a' && *p1 <= 'z' )
			(*(p2+1))++;
		else if( *p1 == ' ' )
			(*(p2+2))++;
		else if( *p1 >= '0' && *p1 <= '9' )
			(*(p2+3))++;
		else
			(*(p2+4))++;
	}
 } 
