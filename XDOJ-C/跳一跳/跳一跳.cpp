#include<stdio.h>
int main()
{
	int a[1000];
	int i, flag = 2, points = 0;
	for( i=0; i < 1000; i++ )    //ÊäÈë Óöµ½ 0 ½áÊø
    {
        scanf( "%d", &a[i] );
        if( a[i] == 0 ) 
			break;
    }
	i = 0;
	while( a[i] != 0 )
	{
		if( a[i] == 1 )
		{
			points += 1;
			flag = 2;
		}
		else if( a[i] == 2 )
		{
			points += flag;
			flag += 2;
		}
		i++;
	}
	printf( "%d", points );
	return 0;
 } 
