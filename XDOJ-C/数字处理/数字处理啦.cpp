#include<stdio.h>
int yushuyuhe(int n)
{
	int p, sum = 0;
	while (n > 0)
	{
		p = n % 10;
		sum = sum + p;
		n = n / 10;
	}

	if (sum < 10)
		return sum;
	if (sum >= 10)
		return yushuyuhe(sum);
}

int main()
{
	int a, res;
	scanf ("%d", &a);
	res = yushuyuhe(a);
	printf ("%d", res);
 } 
