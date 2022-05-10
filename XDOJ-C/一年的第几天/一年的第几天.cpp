#include <stdio.h>
int main ()
{
	int year, month, day, i;
	int a[12] = { 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31 }; 
	scanf ( "%d%d%d", &year, &month, &day );
	if (( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 ))
		a[1] = 29;
	for ( i = 0; i < month - 1; i++ )
		day = day + a[i];
	printf ( "%d", day);
	return 0;
 } 
