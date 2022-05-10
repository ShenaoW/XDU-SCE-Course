#include<stdio.h>
int main()
{
	int a[10], b[9];
	int i, k = 0;
	for( i = 0; i < 10; i++ )
		scanf( "%d", &a[i] );
	for( i = 0; i < 9; i++ )
		b[k++] = a[i+1] / a[i];
	for( i = 0; i < 9; i++ )
		printf( "%d ", b[i] );
	return 0;
 } 
