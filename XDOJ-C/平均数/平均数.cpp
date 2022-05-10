#include<stdio.h>
int main()
{
	int n, i, a[100];
	float sum = 0, aver;
	scanf( "%d", &n );
	for ( i = 0; i < n; i++ ) 
		scanf ( "%d", &a[i] );
	for ( i = 0; i < n; i++ )
		sum = sum + a[i];
	aver = sum / n;
	printf ( "%.2f\n", aver);
	return 0;
 } 
