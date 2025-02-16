#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

//主函数 
int main() 
{
	int count=0;//已记录的学生人数
	int goodcount=0;//已记录的商品数
	int dealcount=0;//已记录的交易数 
	FILE *fp;
	if((fp=fopen("student.txt","r"))==NULL) writesFile(count);
	if((fp=fopen("commodity.txt","r"))==NULL) writecFile(goodcount);
	if((fp=fopen("sdeal.txt","r"))==NULL) writedFile(dealcount);
	count=readsFile();
	goodcount=readcFile();
	dealcount=readdFile();
	menu(count,goodcount,dealcount);//进入菜单 
	return 0;
}

//主菜单 
void menu(int count,int goodcount,int dealcount)
{
	printf("****************************************************************************\n");
	printf("                      欢迎来到校园二手物品交易管理系统                      \n");
	printf("                            请输入要进行的操作：                            \n");
	printf("                              1学生个人信息                                 \n");
	printf("                              2二手物品信息                                 \n");
	printf("                              3交易信息                                     \n");
	printf("                              4退出系统                                     \n");
	printf("****************************************************************************\n");
	int flag=1;//flag==1代表输入错误，需要重新输入 
	while(flag==1) 
	{
		flag=0; 
		int ch;
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: 
				 system("cls");
				 studentmenu(count,goodcount,dealcount);
		         break;
			case 2:
				 system("cls");
		         commoditymenu(count,goodcount,dealcount);
				 break;
			case 3:  
				 system("cls");
		         dm(count,goodcount,dealcount);
				 break;	
			case 4:  
				 system("cls");
				 printf("****************************************************************************\n");
				 printf("退出成功\n");
				 exit(0); 
				 break;		
			default:
				printf("输入错误，请重新输入\n");
				flag=1;
				break;
		}
	}
}


 
