#include<stdio.h>
int main()
{
	struct student
	{
		int numb;
		int hour1;
		int min1;
		int hour2;
		int min2;
	}stu[100], temp;
	int n, i, j;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		scanf( "%d %d:%d %d:%d", &stu[i].numb, &stu[i].hour1, &stu[i].min1, &stu[i].hour2, &stu[i].min2 );
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
		{
			if( (stu[j].hour2 - stu[j].hour1) < (stu[j+1].hour2 - stu[j+1].hour1) )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
			else if( (stu[j].min2 - stu[j].min1) < (stu[j+1].min2 - stu[j+1].min1) )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
			else if( stu[j].numb > stu[j+1].numb )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
		 } 
	for( i = 0; i < n; i++ )
		printf( "%d %02d:%02d %02d:%02d %d\n", stu[i].numb, stu[i].hour1, stu[i].min1, stu[i].hour2, stu[i].min2, (stu[i].hour2 - stu[i].hour1)*60 +(stu[i].min2 - stu[i].min1) );
	return 0;
 } 
