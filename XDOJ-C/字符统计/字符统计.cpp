#include<stdio.h>
#include<string.h>
int main()
{
	char c, C, s[100];
	int n, i, count = 0;
	scanf( "%c%d", &c, &n );
	scanf( "%s", &s );
	if( n == 0 )
	{
		if( c >= 'a' && c <= 'z' )
			C = c + 'A' - 'a';
		else if( c >= 'A' && c <= 'Z' )
		{
			C = c;
			c = c + 'a' - 'A';
		}	
		for( i = 0; s[i]; i++ )
			if( s[i] == c || s[i] == C )
				count++;
	}
	else if( n == 1 )
	{
		for( i = 0; s[i]; i++ )
			if( s[i] == c )
				count++;
	}
	printf( "%d", count );
	return 0;
 } 
