#include<stdio.h>
#include<string.h>
int main()
{
	void fun( char *p1, char *p2 );
	char a[100], b[100];
	scanf( "%s", a );
	fun(a,b);
	printf( "%s", b );
	return 0;
} 
void fun( char a[], char b[] )
{
 	int i, j = 0;
 	for( i = 0; i < strlen(a); i++ )
 	{
 		if( i % 2 == 0 && a[i] )
 		{
 			b[j] = a[i];
 			j++;
		 }
	 }
	 b[j] = '\0';
} 
