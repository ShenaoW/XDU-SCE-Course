#include<stdio.h>
int main()
{
	int n, i, j, s, t = 1, sum = 0;
	scanf ( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= i; j++ )
		t = t * j;
		{
			sum = sum + t;
			s = t;
			t = 1;
		}
	}
	printf ( "%d %d %d", n, s, sum );
	return 0;
 } 
