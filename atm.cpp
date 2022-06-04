#include<stdio.h>
#include<stdlib.h> 

struct Account
{
	char name[100];
	char tel[12];
	char idCard[19];	
	char username[20];
	char password[7];
	float money;
	
	struct Account * next; 
};
typedef struct Account Account; 

Account * head;
Account * tail;

void showMenuEnglish()
{
	
}

void signUpChinese()
{
	
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("请输入姓名：\n"); 
	scanf("%s",newNodeP->name);
	
	printf("请输入电话：\n");
	scanf("%s",newNodeP->tel); 
	
	printf("请输入身份证：\n");
	scanf("%s",newNodeP->idCard); 
	
	printf("请输入账号：\n");
	scanf("%s",newNodeP->username); 
	
	printf("请输入密码：\n");
	scanf("%s",newNodeP->password); 
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	} 
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("添加成功\n");
	system("pause");
}

void signInChinese()
{
	
}

void signOut()
{
	exit(0);
}

void showMenuChinese()
{
	while(1)
	{
		system("cls");
		printf("按1，开户\n");
		printf("按2，登录\n");
		printf("按3，退出\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpChinese();
		}
		else if(n==2)
		{
			signInChinese();
		}
		else if(n==3)
		{
			signOut();
		}
	}
}

int main()
{
	printf("Press 1, English Service\n");
	printf("按2，中文服务\n");
	int language;
	scanf("%d",&language);
	if(language==1)
	{
		showMenuEnglish();
	}
	else if(language==2)
	{
		showMenuChinese(); 
	}
	return 0;
}
