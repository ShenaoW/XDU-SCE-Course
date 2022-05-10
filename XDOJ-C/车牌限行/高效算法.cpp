#include<stdio.h>
int main ()
{
	int day, numb, car;
	scanf ( "%d%d%d", &day, &numb, &car );
	car = car % 10;
	if ( day == 6 || day == 7 )
		printf ( "%d no", car );
	else if (( numb >= 200 && numb < 400 ) && ( day % 5 == car % 5 ))
		printf ( "%d yes", car );
	else if ( numb >= 400 && day % 2 == car % 2 )
		printf ( "%d yes", car );
	else
		printf ( "%d no", car );
	return 0;
 } 
