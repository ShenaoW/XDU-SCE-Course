#include<stdio.h>
int main()
{
	char bds[50], op;
	int i, j, flag = 0, k = 0, numb[2] = {0};
	gets(bds);
	for( i = 0; bds[i]; i++ )
	{
		if( bds[i] == '+' || bds[i] == '-' || bds[i] == '*' || bds[i] == '/' || bds[i] == '%' )
			op = bds[i];
		if( ( bds[i] >= '0' && bds[i] <= '9' ) && flag == 0 )
		{
			for( j = i; bds[j] != ' ' && bds[j] != '\0'; j++ )
				numb[k] = numb[k] * 10 + bds[j] - '0';
			flag = 1;
			k++;
		}
		if( bds[i] == ' ' )
			flag = 0;
	}
	if( op == '+')
		printf( "%d", numb[0] + numb[1] );
	else if( op == '-')
		printf( "%d", numb[0] - numb[1] );
	else if( op == '*')
		printf( "%d", numb[0] * numb[1] );
	else if( op == '/')
		printf( "%d", numb[0] / numb[1] );
	else if( op == '%')
		printf( "%d", numb[0] % numb[1] );
	return 0;
}
