#include<stdio.h>
int main()
{
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	int a[10];
	int p, i, k = 0;
	scanf( "%d", &p );
	for( i = 0; i <= p; i++ )
		a[i] = array[i];
	for( i = 0; i < 10 - p - 1; i++ )
		array[i] = array[p+i+1];
	for( i = 10 - p - 1; i < 10; i++ )
		array[i] = a[k++];
	for( i = 0; i < 10; i++ )
		printf( "%d ", array[i] );
	return 0;
 } 
