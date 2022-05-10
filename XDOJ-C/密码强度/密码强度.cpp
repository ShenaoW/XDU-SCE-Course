#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0, score = 1, count = 0;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
	char mi[50];
	gets(mi);
	if( mi[0] == '\0' )
		score = 0;
	if( strlen(mi) > 8 )
		score ++;
	while( mi[i] != '\0' )
	{
		if( mi[i] >= 'A' && mi[i] <= 'Z' ) k1 = 1;
		else if( mi[i] >= 'a' && mi[i] <= 'z' ) k2 = 1;
		else if( mi[i] >= '0' && mi[i] <= '9' ) k3 = 1;
		else k4 = 1;
		i++;
	}
	count = k1 + k2 + k3 + k4;
	if( count == 2 )
		score += 1;
	else if( count == 3 )
		score += 2;
	else if( count == 4 )
		score += 3;	
	printf( "%d", score );
	return 0;
 } 
