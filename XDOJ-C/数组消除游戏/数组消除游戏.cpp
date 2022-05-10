#include<stdio.h>
int main()
{
	int a[30][30], b[30][30];  //a数组用于判断横向，b数组用于判断纵向，最终结果储存在a数组中. 
	int n, m, i, j, t1, t2; 
	scanf( "%d%d", &n, &m );
	for( i = 0; i < n; i++ )
		for( j= 0; j < m; j++ )
		{
			scanf( "%d", &a[i][j] );
			b[i][j] = a[i][j];
		}
	for( i = 0; i < n; i++ )
	{
		for( j= 0; j < m; j++ )
		{
			if( a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2] )    //横向判断 
			{
				a[i][j] = 0;
				a[i][j+1] = 0;
				t1 = j+2;       //相邻三个数相等时，先令前两个数为0，在对第三个及以后的数进行判断 
				t2 = j+3;
				while( a[i][t1] == a[i][t2] )   //如果三四相等，令三为0，同时此时下标指向四五 
				{
					a[i][t1] = 0;
					t1++;
					t2++;
				}
				a[i][t1] = 0;    //若四五不相等，跳出循环，令四等于0 
			}
			if( b[i][j] == b[i+1][j] && b[i+1][j] == b[i+2][j] )    //纵向判断 
			{
				a[i][j] = 0;      //由于最终结果储存在a数组中，所以此处改变a数组的值即可. 
				a[i+1][j] = 0;
				t1 = i + 2;
				t2 = i + 3;
				while( b[t1][j] == b[t2][j] )
				{
					a[t1][j] = 0;
					t1++;
					t2++;
				}
			 } 
		}
 	}
 	for( i = 0; i < n; i++ )
	{
		for( j= 0; j < m; j++ )
			printf( "%d ", a[i][j] );
		printf( "\n" );
	}
	return 0;
 } 
