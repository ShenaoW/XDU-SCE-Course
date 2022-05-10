#include<stdio.h>
int main()
{
	int a[100], b[100] = {0};
	int n, k, i, j = 0;
	scanf( "%d%d", &n, &k );
	for( i = 0; i < n; i++ )
		scanf( "%d", &a[i] );
	for( i = 0; i < n; i++ )
		if( a[i] == k )		
			b[j++] = i;
	j = 0;
	if( b[0] == 0 )
		printf( "-1" );
	else
		while( b[j] != 0 )
			printf( "%d ", b[j++] );
	return 0;
 } 
