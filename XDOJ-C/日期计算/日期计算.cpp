#include<stdio.h>
int main()
{
	int month_day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 0, y, d;
	scanf( "%d%d", &y, &d );
	if( ( y % 4 == 0 && y % 100 != 0 ) || (y % 400 == 0 ) )
		month_day[2] = 29;
	while( d > month_day[i] )
		d -= month_day[i++];
	printf( "%d %d", i, d );
	return 0;
 } 
