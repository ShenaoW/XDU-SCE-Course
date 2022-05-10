#include<stdio.h>
int main()
{
	int i, j, n, t, shuwei, s[10] = {0}, k = 0;
	scanf( "%d", &n );
	while( n != 0 )
	{
		s[k++] = n % 10;
		n /= 10;
		shuwei++; 
	}
	for( i = 0; i < shuwei - 1; i++ )
		for( j = 0; j < shuwei - 1 - i; j++ )
			if( s[j] < s[j+1] )
			{
				t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}
	for( i = 0; i < shuwei; i++ )
		printf( "%d ", s[i] );
	return 0;
} 
