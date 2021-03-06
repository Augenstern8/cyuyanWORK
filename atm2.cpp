#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Account
{
	char username[100];
	char password[100];
	
	struct Account *next;
};
typedef struct Account Account;

Account *head=NULL;//指向头结点 
Account *tail=NULL;//指向尾结点 

Account *curAccount=NULL;//记录当前账户 

//找到返回1，否则返回0 
int findAccount(Account a)
{
	Account *curp=head;
	while(curp!=NULL)
	{
		if((strcmp(curp->username,a.username)==0)&&(strcmp(curp->password,a.password)==0))
		{
			curAccount=curp; 
			return 1;
		}
		curp=curp->next;
	}
	return 0;
}

void updatePassword()
{
	printf("请输入旧密码：");
	char oldPassword[100];
	scanf("%s",oldPassword);
	if(strcmp(oldPassword,curAccount->password)==0)
	{
		printf("请输入新密码：");
		scanf("%s",curAccount->password);
		printf("修改成功！\n");
	}
	else
	{
		printf("密码错误！不能修改！\n");
	}
}

void signIn()
{
	for(int i=0;i<3;i++)
	{
		Account a; 
		printf("请输入账号：");
		scanf("%s",a.username);
		
		printf("请输入密码：");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			printf("登录成功！\n");
			updatePassword();
			break;
		}
		else
		{
			printf("登录失败！\n");
		}
	}
}

//加载成功返回1，否则返回0 
int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password);
			
			//添加结点到链表 
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		return 1;
	}
}

int main()
{
	int status=loadData(); 
	signIn();
	return 0;
}

