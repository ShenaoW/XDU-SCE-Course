#include<stdio.h>
int main()
{
	struct student
	{
		int numb;
		int time;
	}stu[100] = {0,0}, temp;   //����ṹ�� 
	int n, i, j, hour1, hour2, min1, min2, time[i], numb[i];
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d %d:%d %d:%d", &numb[i], &hour1, &min1, &hour2, &min2 );
		time[i] = ( hour2 - hour1 ) * 60 + ( min2 - min1 );
	}    //��ȡ�����������룬�ֱ�Ϊ��ź͵���ʱ�� 
	for( i = n; i > 1; i-- )
	{
		if (numb[i] == stu)
		for( j = 0; j <= i; j++ )
		{
			if( numb[j] == numb[i] )
			{
				stu[ numb[i] ].numb = numb[i];   //������ż�һλ�õ�stu�ṹ�������� 
				stu[ numb[i] ].time += time[j];
			}
		}
	}   //������������ͬ��ŵĵ���ʱ���ϲ�������ṹ������ 
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
