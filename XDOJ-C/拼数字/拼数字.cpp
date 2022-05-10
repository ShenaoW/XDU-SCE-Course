#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i, numb = 0;
	scanf( "%s", a );
	for( i = 0; i < strlen(a); i++ )
		if( a[i] >= '0' && a[i] <= '9' )
			numb = numb * 10 + (a[i] - '0');
	if( numb == 0 )
		printf( "0" );
	else
	{
		for( i = numb - 1; i > 1; i-- )
			if( numb % i == 0 )
			{
				printf( "%d", i );
				break;
			}
		if( i == 1 )
		printf( "%d", numb );			
	}
	return 0;
 } 
