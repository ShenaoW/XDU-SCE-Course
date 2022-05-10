#include<stdio.h>
int main()
{
	struct Student
	{
		char stu[100];
		int grade;
		int english;
	}student[100],t;
	int m, n, i, j;
	scanf( "%d%d", &m, &n );
	for( i = 0; i < m; i++ )
		scanf( "%s%d%d", &student[i].stu, &student[i].grade, &student[i].english );
	for( i = 0; i < m - 1; i++ )
	{
		for( j = 0; j < m - 1 - i; j++ )
		{
			if( student[j].grade < student[j+1].grade )
			{
				t = student[j];
				student[j] = student[j+1];
				student[j+1] = t;
			}
			else if( student[j].grade == student[j+1].grade )
			{
				if( student[j].english < student[j+1].english )
				{
					t = student[j];
					student[j] = student[j+1];
					student[j+1] = t;
				}
				else if( student[j].english == student[j+1].english )
				{
					if( student[j].stu > student[j+1].stu )
					{
						t = student[j];
						student[j] = student[j+1];
						student[j+1] = t;	
					}
				}
			}
		}
	}
	for( i = 0; i < n; i++ )
		printf( "%s %d %d\n", student[i].stu, student[i].grade, student[i].english );
	return 0;
}







