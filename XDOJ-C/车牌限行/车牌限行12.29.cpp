#include<stdio.h>
int main()
{
	int day, mai, che; 
	scanf( "%d%d%d", &day, &mai, &che );
	che = che % 10;
	if( day >= 1 && day <= 5 && mai >= 200 )
	{
		if( mai < 400 && che % 5 == day % 5 )
			printf( "%d yes", che );
		else if( mai >= 400 && che % 2 == day % 2 )
			printf( "%d yes", che );
		else
			printf( "%d no", che );
	}
	else
		printf( "%d no", che );
	return 0;
 } 
