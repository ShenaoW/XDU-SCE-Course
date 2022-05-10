#include<stdio.h>
int main()
{
	int n, i, x[100], t, j, cha, zhi, flag = 0;
	scanf ("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &x[i]);
	}
	for (j = 1;j < n;j++)/*外循环*/
		for (i = 0;i < n-j;i++)/*相邻两个数比较*/
		{
			if (x[i] > x[i+1])
			{
				t = x[i];
				x[i] = x[i+1];
				x[i+1] = t;
			}
		}
	cha = x[1] - x[0];
	for (i = 1;i < n-1;i++)
	{
		zhi = x[i+1] - x[i];
		if (zhi != cha)
			flag += 1;
	}
	if (flag != 0)
		printf("no");
	else
		printf("%d", cha);
 } 
