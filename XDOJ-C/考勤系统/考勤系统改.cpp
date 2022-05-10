#include<stdio.h>
int main()
{
	struct student
	{
		int numb;
		int time;
	}stu[100] = {0,0}, temp;   //定义结构体 
	int n, i, j, hour1, hour2, min1, min2, time[i], numb[i];
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d %d:%d %d:%d", &numb[i], &hour1, &min1, &hour2, &min2 );
		time[i] = ( hour2 - hour1 ) * 60 + ( min2 - min1 );
	}    //获取两个数组输入，分别为序号和单词时长 
	for( i = n; i > 1; i-- )
	{
		if (numb[i] == stu)
		for( j = 0; j <= i; j++ )
		{
			if( numb[j] == numb[i] )
			{
				stu[ numb[i] ].numb = numb[i];   //放入序号减一位置的stu结构体数组中 
				stu[ numb[i] ].time += time[j];
			}
		}
	}   //将两数组中相同序号的单次时长合并，放入结构体数组 
	for( i = 0; i < n - 1; i++ )
		for( j = 0; j < n - 1 - i; j++ )
		{
			if( stu[j].time < stu[j+1].time )
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
	for( i = 1; i < n; i++ )
		if (stu[i].numb == 0) break;
		printf( "%d %d\n", stu[i].numb, stu[i].time );
	return 0;
 } 
