#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct commodity com[50];

//上架 
void on(int count,int goodcount,int dealcount)
{
	int flag=0;//记录卖家是否存在 
	
	printf("请输入商品信息：\n");
	system("pause");
	
	printf("请输入商品的名称：");
	scanf("%s",com[goodcount].cname);
	
	printf("请输入商品的价格：");
	scanf("%d",&com[goodcount].price);
	
	printf("请输入商品的数量：");
	scanf("%d",&com[goodcount].amount);
	
	printf("请输入商品的卖家：");
	scanf("%s",com[goodcount].sname);
	
	////判断用户是否存在于系统中
	for(int j=0;j<count;j++)
	{
		if(strcmp(stu[j].name,com[goodcount].sname)==0)
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		printf("上架成功\n");
		goodcount++;
	}
	else printf("卖家不存在\n上架失败\n");
	
	system("pause"); 
	system("cls");
	
	writecFile(goodcount);//写入文件
	
	commoditymenu(count,goodcount,dealcount);//返回商品菜单 
}

//下架 
void down(int count,int goodcount,int dealcount)
{
	int flag=0;//记录该商品信息是否存在 flag=1代表存在并下架 flag=0代表不存在
	
	char cname [20];
	
	printf("请输入下架的商品名称:");
	scanf("%s",cname);
	
	for(int i=0;i<goodcount;i++)
	{
		if(strcmp(com[i].cname,cname)==0)
		{
		   flag=1; //商品存在 
		   for(int j=i;j<goodcount-1;j++)
		   {
		   	 com[j]=com[j+1];
		   }
		}
		if(flag==1)break;
	}
	
	if(flag==0) printf("该商品不存在\n");
	if(flag==1) 
		{
			printf("下架成功\n");
			goodcount--;
		}
		
	system("pause");
	system("cls");
	
	writecFile(goodcount);//写入文件 
	
	commoditymenu(count,goodcount,dealcount);//返回商品菜单 
}

//排序 (按价格排序)
void sort(int count,int goodcount,int dealcount) 
{
	//判断系统中是否存在商品信息
	if(goodcount==0)printf("暂无商品信息\n");
	
	//菜单选项 
	printf("****************************************************************************\n");
 	printf("排序方式：\n");
 	printf("1按价格升序\n");
 	printf("2按价格降序\n");
 	printf("****************************************************************************\n");
 	
 	//获取用户输入 
 	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		case 1:
  			//按价格升序
  		    for(int i=0;i<goodcount;i++)
		  	{
		  		for(int j=0;j<goodcount-i-1;j++)
		  		{
		  			//比较商品价格高度
		  			if(com[j].price>com[j+1].price)
		  			{
					  	struct commodity t;//暂时存储信息
						t=com[j];
						com[j]=com[j+1];
						com[j+1]=t;
					}
		  		}
		  	}
		  	cprint(count,goodcount,dealcount);//输出结果 
  			break;
  			
  		case 2:
  			//按价格降序
  			for(int i=0;i<goodcount;i++)
	  		{
  		  		for(int j=0;j<goodcount-i-1;j++)
  		  		{
  		  			if(com[j].price<com[j+1].price)
  		  			{
  					  	struct commodity t;
						t=com[j];
						com[j]=com[j+1];
						com[j+1]=t;
  					}
  		  		}
	  		}
	  		cprint(count,goodcount,dealcount);
  			break;
  			
  		default:
  			printf("输入错误，请重新输入\n");
  			system("pause");
  			break;
  	}
  	
	system("pause");
	system("cls");
	
	writecFile(goodcount);// 写入文件 
	
	commoditymenu(count,goodcount,dealcount);//返回商品菜单 
}

//修改 
void goodmodify(int count,int goodcount,int dealcount)
{
	int price;//存放修改为的价格 
	int amount;//存放修改为的数量 
	char sname [20];//存放修改为的卖家 
	char cname [20];//存放修改为的名称 
	char modi [20];//用于查找商品
	
	int x;//存放待修改商品的信息所在数组下标
	
	int flag=0;//记录该商品信息是否存在 flag=1代表存在并修改 flag=0代表不存在
	
	 //查找商品 
	printf("请输入需要修改的商品的名称:");
	scanf("%s",modi);
	for(int i=0;i<goodcount;i++)
	{
		if(strcmp(com[i].cname,modi)==0)
		{
			flag=1;//找到商品 
			
			x=i;//记录找到的商品 
			
			printf("****************************************************************************\n");
		  	printf("请输入要进行的操作：\n");
		  	printf("1修改名称\n");
		  	printf("2修改价格\n");
		  	printf("3修改数量\n");
		  	printf("4修改卖家\n");
		  	printf("****************************************************************************\n");
		  	
		  	int ch;
		  	scanf("%d",&ch);
		  	switch (ch)
		  	{
		  		case 1:
		  			printf("修改为："); 
		  			scanf("%s",cname);
		  			strcpy(com[x].cname,cname);
		  			break;
		  		case 2:
		  			printf("修改为："); 
		  			scanf("%d",&price);
		  			com[x].price=price;
		  			break;
		  		case 3:
		  			printf("修改为："); 
		  			scanf("%d",&amount);
		  			com[x].amount=amount;
		  			break;
		  		case 4:
		  			printf("修改为："); 
		  			scanf("%s",sname);
		  			strcpy(com[x].sname,sname);
		  			break;
		  		default:
		  			flag=2;//不输出结果语句 
		  			printf("输入错误，请重新输入\n");
		  			system("pause");
		  			break;
			  	}
		}
	}
	
 	if(flag==0) printf("该商品不存在\n");
 	if(flag==1) 
 		{
 			printf("修改成功\n");
 		}
 		
 	system("pause");
 	system("cls");
 	
 	writecFile(goodcount);//写入文件 
 	
	commoditymenu(count,goodcount,dealcount);//返回商品菜单 
}

//查找 
void goodsearch(int count,int goodcount,int dealcount)
{
	
	char s [20];
	int flag=0;//记录该商品信息是否存在 flag=1代表存在 flag=0代表不存在
	
	printf("****************************************************************************\n");
 	printf("查找方式：\n");
 	printf("1按名称查找\n");
 	printf("2按卖家查找\n");
 	printf("****************************************************************************\n");	
 	
	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		//通过名称查找 
  		case 1:
  		    printf("请输入需要查找的商品的名称：");
		 	scanf("%s",s);
		 	for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(com[i].cname,s)==0)
		 		{
		 			flag=1;
		 			printf("****************************************************************************\n");
					printf("名称:%s\t价格:%d\t数量:%d\t卖家:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
					printf("****************************************************************************\n");	
		 		}
		 	}
  			break;
  			
  		//通过卖家查找 
  		case 2:
  			printf("请输入需要查找的商品的卖家：");
		 	scanf("%s",s);
		 	for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(com[i].sname,s)==0)
		 		{
		 			flag=1;
		 			printf("****************************************************************************\n");
		 			printf("名称:%s\t价格:%d\t数量:%d\t卖家:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
		 			printf("****************************************************************************\n");
		 		}
		 	}	
  			break;
  			
  		default:
  			printf("输入错误，请重新输入\n");
  			flag=2;
  			break;
  	}
  	
	if(flag==0)printf("商品不存在\n");
	
	system("pause");
	system("cls");
	
	commoditymenu(count,goodcount,dealcount);//返回商品菜单 
}

//输出 
void cprint(int count,int goodcount,int dealcount)
{
	
	if(goodcount==0) printf("暂无商品信息\n");
	
	for(int i=0;i<goodcount;i++)
	{
		printf("****************************************************************************\n");
		printf("名称:%s\t价格:%d\t数量:%d\t卖家:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
		printf("****************************************************************************\n");
	}
	
	system("pause"); 
	system("cls");
	
	commoditymenu(count,goodcount,dealcount);
} 

//文件保存 
void writecFile(int goodcount)
{
	FILE *fp=fopen("commodity.txt","w");
	
	if( fp== NULL )
	{
		printf("fail to open\n");
		perror("fopen");
		exit(0);
	}
	
	fprintf(fp,"%d",goodcount);
	
	for(int i=0;i<goodcount;i++)
	{
		fwrite(&com[i],sizeof(struct commodity),1,fp);
	}
	
	fclose(fp);
		
	fp=NULL;
}

//文件读取 
int readcFile()
{
	FILE *fp=fopen("commodity.txt","r");
	
	if( fp==NULL )
	{
		printf("fail to open\n");
		exit(0);
	}
	
	int goodcount=0;
	fscanf(fp,"%d",&goodcount);
	
	for(int i=0;i<goodcount;i++)
	{
		fread(&com[i],sizeof(struct commodity),1,fp);
	}
	
	fclose(fp);
	
	fp=NULL;
	
	return goodcount;
}

//商品子目录 
void commoditymenu(int count,int goodcount,int dealcount)
{
    printf("****************************************************************************\n");
	printf("物品信息\n");
	printf("请输入要进行的操作：\n");
	printf("1上架\n");
	printf("2下架\n");
	printf("3排序\n");
	printf("4修改\n");
	printf("5查找\n");
	printf("6输出\n");
	printf("7返回\n");
	printf("****************************************************************************\n");
	int flag=1;//flag==1代表输入错误，需要重新输入 
	while(flag==1) 
	{
		int ch;
	 	scanf("%d",&ch);
	 	switch (ch)
	 	{
	 		case 1:
	 			system("cls");
	 			on(count,goodcount,dealcount); 
	 			break;
	 		case 2:
	 			system("cls");
	 			down(count,goodcount,dealcount); 
	 			break;
	 		case 3:
	 			system("cls");
	 			sort(count,goodcount,dealcount);
	 			break;
	 		case 4:
	 			system("cls");
	 			goodmodify(count,goodcount,dealcount);
	 			break;
	 		case 5:
	 			system("cls");
	 			goodsearch(count,goodcount,dealcount);
	 			break;
	 		case 6:
	 			system("cls");
			 	cprint(count,goodcount,dealcount);
				break;  
	 		case 7:
				system("cls");
				writecFile(goodcount);
			  	menu(count,goodcount,dealcount);//返回主菜单 
			  	break;
	 		default:
	 			printf("输入错误，请重新输入\n");
	 			flag=1; 
	 			break;
	 	}
 	}
 	
}
