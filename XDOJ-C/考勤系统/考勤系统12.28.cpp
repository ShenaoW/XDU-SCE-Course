#include<stdio.h>
int main()
{
	struct Student
	{
		int numb;
		int time;
	}stu[100] = {0}, t;
	int a[100], hour1[100], hour2[100], min1[100], min2[100];
	int i, j, n, max;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		scanf( "%d %d:%d %d:%d", &a[i], &hour1[i], &min1[i], &hour2[i], &min2[i] );
	max = a[0];
	for( i = 0; i < n; i++ )
	{
		stu[a[i]].numb = a[i];
		stu[a[i]].time += ( ( hour2[i] - hour1[i] ) * 60 + ( min2[i] - min1[i] ) );
		max = max > a[i] ? max : a[i];
	}
	for( i = 0; i < max; i++ )
		for( j = 0; j < max - i; j++ )
		{
			if( stu[j].time < stu[j+1].time )
			{
				t = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = t;
			}
			else if( stu[j].time == stu[j+1].time )
				if( stu[j].numb > stu[j+1].numb )
				{
					t = stu[j];
					stu[j] = stu[j+1];
					stu[j+1] = t;
				}
		}
	for( i = 0; stu[i].numb != 0; i++ )
	{
		printf( "%d %d", stu[i].numb, stu[i].time );
		if( stu[i+1].numb != 0 )
			printf( "\n" );
	}
	return 0;
 } 
