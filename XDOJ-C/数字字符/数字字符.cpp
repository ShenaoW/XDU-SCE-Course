#include<stdio.h>
int main()
{
	int a;
	char b; 
	scanf ( "%d,%c", &a, &b );
	printf ( "%d,%d", a+b, a+b-'0' );
	return 0;
} 
