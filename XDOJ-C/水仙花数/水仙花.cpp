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
	}  // a中存放小数，则区间为[a,b] 
	a = a > 100 ? a : 100;
	for( i = a; i <= b; i++ )
	{
		t = i;
		n = 0;  //临时变量存放该数原值，在此基础上计算 <数位n> 及 <各位数的n次方和> 
		while( t != 0 )
		{
			t = t / 10;  
			n++; 
		}    //计算出数位n 
		t = i; 
		sum = 0;	
		while( t != 0 )
		{
			sum += pow( (t % 10), n );   //pow函数用来计算n次方，sum表示 < 各位数n次方和 >
			t = t / 10;
		}
		if( sum == i )
			numb++;
		
	}
	return numb;
}
