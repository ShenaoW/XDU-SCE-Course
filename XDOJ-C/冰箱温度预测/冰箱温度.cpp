#include<stdio.h>
int main()
{
	float T,h,t,m;
	scanf("%f%f",&h,&m);
    t=h+m/60;
    T=(4*t*t)/(t+2)-20;
    printf("%.2f",T);
    return 0;
		
	
}
