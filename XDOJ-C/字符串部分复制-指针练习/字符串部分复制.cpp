#include<stdio.h>
#include<string.h>
void copystr( char *s, int n );
int main()
{
	char str[50];
	int m;
	gets(str);
	scanf("%d",&m);
	copystr(str,m);
	return 0;
 } 
 
 void copystr(char *s, int n)
 {
 	char s2[50];
 	int i,j = 0;
 	if (strlen(s)<n)
 	{
 		printf("error");
	 }
	 else
	 {
	 	for (i=n-1;i<strlen(s);i++)
	 	{
	 		s2[j++]=s[i];
		 }
		 s2[j] = '\0';
		 printf("%s",s2); 
	 }
 }
