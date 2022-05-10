#include<stdio.h>
int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10}, a[10];
	int p, i, k = 0;
	scanf( "%d", &p );
	for( i = p + 1; i < 10; i++ )
		a[k++] = array[i];
	for( i = 0; i <= p; i++ )
		a[k++] = array[i];
	for( i = 0; i < 10; i++ )
		printf( "%d ", a[i] );
	return 0;
	
 } 
