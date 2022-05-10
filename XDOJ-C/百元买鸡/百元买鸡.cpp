#include<stdio.h>
int main()
{
	struct Fangan
	{
		int gong;
		int mu;
		int xiao;
	}fangan[100] = {0}, t;
	int i, j, k = 0;
	for( i = 1; i <= 100; i++ )
		for( j = 1; j <= 100; j++ )
			if( 5 * i + 3 * j + (100-i-j)/3.0 == 100 )
			{
				fangan[k].gong = i;
				fangan[k].mu = j;
				fangan[k++].xiao = 100 - i - j;
			}
	for( i = 0; i < k - 1; i++ )
		for( j = 0; j < k - 1 - i; j++ )
			if( fangan[j].gong > fangan[j+1].gong )
			{
				t = fangan[j];
				fangan[j] = fangan[j+1];
				fangan[j+1] = t;
			}
	for( i = 0; i < k; i++ )
	{
		printf( "%d %d %d", fangan[i].gong, fangan[i].mu, fangan[i].xiao );
		if( i < k - 1 )
			printf( "\n" );
	} 
	return 0;
 } 
