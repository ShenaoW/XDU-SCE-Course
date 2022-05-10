#include<stdio.h>
int main ()
{
	int n;
	int fib ( int n );
	scanf ( "%d", &n );
	printf ( "%d", fib(n) );
	return 0;
}
int fib ( int n )
{
	int a[100], i;
	a[0] = 7; a[1] = 11;
	for ( i = 2; i <= n; i++ )
		a[i] = a[i - 1] + a[i - 2];
	return a[n];
}
