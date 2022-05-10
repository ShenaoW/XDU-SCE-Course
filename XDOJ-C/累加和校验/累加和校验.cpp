#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i, sum = 0;
	gets(a);
	for( i = 0; i < strlen(a); i++ )
		sum += a[i];
	printf( "%d", sum &0xFF );
	return 0;
 } 
