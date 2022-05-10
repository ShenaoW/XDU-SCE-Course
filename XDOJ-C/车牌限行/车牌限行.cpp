#include<stdio.h>
int main()
{
	int day, level, numb, n;
	scanf ("%d%d%d", &day, &level, &numb);
	printf ("%d ", n = numb % 10);
	if (day == 6 || day == 7)
		printf ("no");
	else if (level < 200) 
		printf ("no");
	else if (level < 400)
		{
			switch (day)
			{
				case 1 : if (n==1 || n==6) printf ("yes"); else printf("no"); break;
				case 2 : if (n==2 || n==7) printf ("yes"); else printf("no"); break;
				case 3 : if (n==3 || n==8) printf ("yes"); else printf("no"); break;
				case 4 : if (n==4 || n==9) printf ("yes"); else printf("no"); break;
				case 5 : if (n==5 || n==0) printf ("yes"); else printf("no"); break;
			}
		
		}
	else 
		{
			switch(day)
			{
				case 1 :
				case 3 :
				case 5 : if (n % 2 != 0) printf ("yes"); else printf ("no"); break;
				case 2 :
				case 4 : if (n % 2 == 0) printf ("yes"); else printf ("no"); break;
			}
		}
	return 0;
 } 
