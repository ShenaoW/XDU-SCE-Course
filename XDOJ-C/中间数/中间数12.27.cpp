#include<stdio.h>
int main()
{
	int i, j, n, count1, count2;
	int a[1000];
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		scanf( "%d", &a[i] );
	for( i = 0; i < n; i++ )
	{
		count1 = 0; count2 = 0;
		for( j = 0; j < n; j++ )
		{
			if( a[i] > a[j] )
				count1++;
			if( a[i] < a[j] )
				count2++; 
		}
		if( count1 == count2 )
		{
			printf( "%d", a[i] );
			break;
		}
	 }
	 if( i == n )
	 	printf( "-1" ); 
	return 0;
 } 
