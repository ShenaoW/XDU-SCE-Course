#include<stdio.h>
#include<string.h>
int main()
{
	char a[255], b[24] = {0}, t;
	int i, j, c[24] = {0}, k = 0;
	gets(a);
	for( i = 0; i < strlen(a); i++ )   
	{
		if( a[i-1] == '-' && c[a[i]-'a'] == 0 )   //��ĳ�ַ�ǰ��-�ţ�����ַ������ҵ�ѡ�� 
		{
			b[k++] = a[i];      //b�����д������г��ֵ�ѡ�� 
			c[a[i]-'a'] = 1;	//c�����д��� ��ѡ���Ƿ���ֹ��������ֹ������Ӧλ�ã�a��Ӧ 1��b��Ӧ 2���Դˣ�Ԫ��Ϊ 1����Ϊ���ֹ�����c�����ӦԪ��Ϊ 0 
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
