#include<stdio.h>
#include<string.h>
int main()
{
	char hang[100][100];
	int i, max_len, max_hang, n = 0, flag = 1;
	for( n = 0; flag != 0; n++ )
	{
		gets( hang[n] );
		if( strcmp(hang[n], "***end***") == 0 )
			flag= 0;
	}
	max_len = strlen( hang[0] );
	max_hang = 0;
	for( i = 1; i < n - 1; i++ )
		if( max_len < strlen( hang[i] ) )
		{
			max_len = strlen( hang[i] );
			max_hang = i;
		}
	printf( "%d\n", max_len );
	printf( "%s", hang[max_hang] );

 } 
