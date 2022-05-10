#include<stdio.h>
int fibs(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else if (n > 2)
		return fibs(n-1) + fibs(n-2);
}
int main()
{	
	int i, m, num, flag = 0;
	scanf ("%d", &i);
	m = fibs(i);	

	for (num = 2;num < m;num++)
	{
		if (m % num == 0) 
			flag++;
	}
	
	if (flag == 0)
		printf("yes");
	else
		printf("%d", m);
	return 0;
}
