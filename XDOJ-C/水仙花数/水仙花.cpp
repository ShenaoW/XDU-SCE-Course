#include<stdio.h> 
#include<math.h>
int main()
{
	int funtion( int a, int b );
	int a, b;
	scanf( "%d%d", &a, &b );
	printf( "%d", funtion(a, b) );
	return 0;
}
int funtion( int a, int b )
{
	int i, t, numb = 0, n = 0, sum = 0;
	if( a > b )
	{
		t = a;
		a = b;
		b = t;
	}  // a�д��С����������Ϊ[a,b] 
	a = a > 100 ? a : 100;
	for( i = a; i <= b; i++ )
	{
		t = i;
		n = 0;  //��ʱ������Ÿ���ԭֵ���ڴ˻����ϼ��� <��λn> �� <��λ����n�η���> 
		while( t != 0 )
		{
			t = t / 10;  
			n++; 
		}    //�������λn 
		t = i; 
		sum = 0;	
		while( t != 0 )
		{
			sum += pow( (t % 10), n );   //pow������������n�η���sum��ʾ < ��λ��n�η��� >
			t = t / 10;
		}
		if( sum == i )
			numb++;
		
	}
	return numb;
}
