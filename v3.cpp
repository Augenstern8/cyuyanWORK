#include<stdio.h>
#include<string.h> 
int main()
{
	char str[]="2+2*3+2/2-1";
	int res=str[0]-'0';
	for(int i=1;i<strlen(str);i++)
	{
		if(str[i]=='+')
		{
			int a=str[i+1]-'0';
			res=res+a;
			i++;
		}
		else if(str[i]=='-')
		{
			int a=str[i+1]-'0';
			res=res-a;
			i++;
		}
	 } 
	for(int i=1;i<strlen(str);i++)
	{
		if(str[i]=='*')
		{
			int a=str[i+1]-'0';
			res=res*a;
			i++;
		}
		else if(str[i]=='/')
		{
			int a=str[i+1]-'0';
			res=res/a;
			i++;
		}
	}
	printf("res=%d",res);
	return 0;
}

