#include<stdio.h>
int main()
{
	struct Wenjian
	{
		int year;
		int month;
		int day;
		int kb;
	}wenjian[100] = {0}, t;
	int n, i, j;
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
		scanf( "%d/%d/%d %d", &wenjian[i].year, &wenjian[i].month, &wenjian[i].day, &wenjian[i].kb );
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
		{
			if( wenjian[j].year < wenjian[j+1].year )
			{
				t = wenjian[j];
				wenjian[j] = wenjian[j+1];
				wenjian[j+1] = t;
			}
			else if( wenjian[j].year == wenjian[j+1].year )
			{
				if( wenjian[j].month < wenjian[j+1].month )
				{
					t = wenjian[j];
					wenjian[j] = wenjian[j+1];
					wenjian[j+1] = t;
				}
				else if( wenjian[j].month == wenjian[j+1].month )
				{
					if( wenjian[j].day < wenjian[j+1].day )
					{
						t = wenjian[j];
						wenjian[j] = wenjian[j+1];
						wenjian[j+1] = t;
					}	
					else if( wenjian[j].day == wenjian[j+1].day )
					{
						if( wenjian[j].kb < wenjian[j+1].kb )
						{
							t = wenjian[j];
							wenjian[j] = wenjian[j+1];
							wenjian[j+1] = t;
						}		
					}
				}
			}
		} 
	for( i = 0; i < n; i++ )
	{
		printf( "%d/%d/%d %d", wenjian[i].year, wenjian[i].month, wenjian[i].day, wenjian[i].kb );
		if( i < n - 1 )
			printf("\n");
	}
	return 0;
 } 
