#include<stdio.h>
#include<string.h>
int main()
{
	char a[255], b[24] = {0}, t;
	int i, j, c[24] = {0}, k = 0;
	gets(a);
	for( i = 0; i < strlen(a); i++ )   
	{
		if( a[i-1] == '-' && c[a[i]-'a'] == 0 )   //若某字符前有-号，则该字符是所找的选项 
		{
			b[k++] = a[i];      //b数组中储存所有出现的选项 
			c[a[i]-'a'] = 1;	//c数组中储存 该选项是否出现过。若出现过，则对应位置（a对应 1，b对应 2，以此）元素为 1，若为出现过，则c数组对应元素为 0 
		}
}
	if( b[0] == '\0' )
	{
		printf( "no" );
	}
	else
	{
		for( i = 0; i < strlen(b) - 1; i++ )
			for( j = 0; j < strlen(b) - 1 - i; j++ )
				if( b[j] > b[j+1] )
				{
					t = b[j];
					b[j] = b[j+1];
					b[j+1] = t;
				}
		for( i = 0; i < strlen(b); i++ )
			printf( "-%c ", b[i] );	
	}
	return 0;
}
