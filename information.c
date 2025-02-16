#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct transaction tran[50];

//生成
void create(int count,int goodcount,int dealcount)
{
	int flag1=0;//记录买家是否存在 
	int flag2=0;//记录商品是否存在
	 
	char bname [20];//记录买家名字 
	char cname [20];//记录商品名字 
	
	printf("请输入买家：");
	scanf("%s",bname);
	
	printf("请输入商品名称：");
	scanf("%s",cname);
	
	//判断用户是否存在于系统中 
	for(int i=0;i<count;i++) 
	{
		if(strcmp(stu[i].name,bname)==0)
		{
			flag1=1;
			tran[dealcount].buyer=stu[i];
		}
	}
	
	if(flag1==0)
	{
		printf("买家不存在\n生成失败");
	}
	
	//买家存在，进一步判断商品是否存在于系统 
	else
	{
		for(int i=0;i<goodcount;i++)
		{
			if(strcmp(com[i].cname,cname)==0)//判断商品是否存在 
			{
				if(com[i].amount==0) flag2=2;//判断商品是否还有库存 
				
				else
				{
					flag2=1;
									
					com[i].amount--;
					
					tran[dealcount].com=com[i];
				}
				
				
				for(int j=0;j<count;j++)//商品存在时录入系统 
				{
					if(strcmp(stu[j].name,com[i].sname)==0)
					{
						tran[dealcount].seller=stu[j]; 
					}
				}
			}
		}
		
		if(flag2==2)printf("商品已售罄\n生成失败\n");//商品卖完时 
		if(flag2==0)printf("商品不存在\n生成失败\n");//商品不存在时 

	}
	
	if((flag1==1)&&(flag2==1))
	{
		dealcount++;
		
		printf("生成成功\n");
	}
	
	system("pause"); 
	system("cls");
	
	writedFile(dealcount);//写入文件 
	
	dm(count,goodcount,dealcount);//返回交易菜单 
}

//输出单个交易信息 
void output(int i)
{
	
	printf("****************************************************************************\n");
 	printf("账单%d：\n",i+1);
 	printf("****************************************************************************\n");
 	
	printf("买家信息\n");
	printf("姓名:%s\t学号:%s\t学院:%s\t班级:%s\t电话:%s\t\n",tran[i].buyer.name,tran[i].buyer.num,tran[i].buyer.college,
															tran[i].buyer.class_,tran[i].buyer.tel);
															
	printf("商品信息\n");
	printf("名称:%s\t价格:%d\t卖家:%s\t\n",tran[i].com.cname,tran[i].com.price,tran[i].com.sname);
	
	printf("卖家信息\n"); 
	printf("姓名:%s\t学号:%s\t学院:%s\t班级:%s\t电话:%s\t\n",tran[i].seller.name,tran[i].seller.num,tran[i].seller.college,
															tran[i].seller.class_,tran[i].seller.tel);
} 

//输出全部交易信息 
void dprint(int count,int goodcount,int dealcount)
{
	if(dealcount==0) printf("暂无交易记录\n");
	
	for(int i=0;i<dealcount;i++)
	{
		output(i);
	}
  	
	system("pause"); 
  	system("cls");
  	
	dm(count,goodcount,dealcount);//返回交易菜单 
}

//查找
void dealsearch(int count,int goodcount,int dealcount)
 {
	int flag=0;//记录该交易信息是否存在 flag=1代表存在 flag=0代表不存在 
	
	//输出菜单选项 
	printf("****************************************************************************\n");
 	printf("查找方式：\n");
 	printf("1买家\n");
 	printf("2商品\n");
 	printf("3卖家\n");
 	printf("****************************************************************************\n");
 	
	 //获取用户选择 
 	int ch;
 	scanf("%d",&ch);
 	switch (ch)
 	{
 		//通过买家搜索 
 		case 1:
 			
 			printf("请输入买家名称：");
			char bname [20];
			scanf("%s",bname);
 			
			 for(int i=0;i<dealcount;i++)
		 	{
		 		if(strcmp(tran[i].buyer.name,bname)==0)//判断是否存在 
		 		{
		 			flag=1;
		 			output (i);//输出信息 
		 		}
		 	}
 			break;
 		
		//通过商品搜索	
 		case 2:
 	
 			printf("请输入商品名称：");
 			char cname [20];
 			scanf("%s",cname);
 			
			 for(int i=0;i<dealcount;i++)
		 	{
		 		if(strcmp(tran[i].com.cname,cname)==0)//判断是否存在 
		 		{
		 			flag=1;
		 			output (i);//输出信息 
		 		}
		 	}
 			break;
 			
 		//通过卖家搜索	
 		case 3:
 			
 			printf("请输入卖家名称：");
 			char sname [20];
			scanf("%s",sname);
 			
			 for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(tran[i].seller.name,sname)==0)//判断是否存在 
		 		{
		 			flag=1;
		 			output (i);//输出信息 
		 		}
		 	}
 			break;
 			
 		default:
 			flag=2;//不输出结果语句 
 			printf("输入错误，请重新输入\n");
 			system("pause");
 			break;
 	}
 	
 	//查找失败 
 	if(flag==0) printf("暂无该交易\n");

	system("pause"); 
 	system("cls");
 	
 	dm(count,goodcount,dealcount);//返回交易菜单 
}

//删除
void dealdel(int count,int goodcount,int dealcount)
{
	int flag=0;//记录该交易信息是否存在 flag=1代表存在 flag=0代表不存在 
	
	printf("请输入买家名称：");
	char bname [20];
	scanf("%s",bname);
	
	printf("请输入商品名称：");
	char cname [20];
	scanf("%s",cname);
	
	printf("请输入卖家名称：");
	char sname [20];
	scanf("%s",sname);
	
	for(int i=0;i<dealcount;i++)
 	{
 		if((strcmp(tran[i].buyer.name,bname)==0)&&(strcmp(tran[i].com.cname,cname)==0)&&(strcmp(tran[i].seller.name,sname)==0))
 		{	  
		    //商品数量加1 
			for(int j=0;j<goodcount;j++)
			{
				if((strcmp(cname,com[j].cname)==0)&&(strcmp(sname,com[j].sname)==0))
				{
					com[j].amount++;
				}
			} 
			
			//删除该交易记录 	
   			for(int j=i;j<dealcount-1;j++)
   		    {
   		   	  tran[j]=tran[j+1];
   		    }
 			dealcount--;//交易信息数量-1 
 			 
			flag=1; 		   				
 		}
 	}
 	
 	if(flag==0) printf("暂无该交易\n");
 	if(flag==1) printf("删除成功\n");
  	
	system("pause"); 
  	system("cls");
  	
	writedFile(dealcount);//写入文件 
	
  	dm(count,goodcount,dealcount);//返回交易菜单 
}

//排序
void dealsort(int count,int goodcount,int dealcount)
{
	//判断系统中是否存在交易信息 
	if(dealcount==0)printf("暂无交易信息\n");
	
	//菜单选项 
	printf("****************************************************************************\n");
 	printf("排序方式：\n");
 	printf("1按商品价格升序\n");
 	printf("2按商品价格降序\n");
 	printf("****************************************************************************\n");
 	
	 //获取用户输入 
	int ch;
 	printf("选择："); 
  	scanf("%d",&ch);
	switch (ch)
  	{
  		//按价格升序 
  		case 1: 
  		    for(int i=0;i<dealcount;i++)
		  	{
		  		for(int j=0;j<dealcount-i-1;j++)
		  		{
		  			//比较商品价格高度 
		  			if(tran[j].com.price>tran[j+1].com.price)
		  			{
					  	struct transaction t;//暂时存储信息 
						t=tran[j];
						tran[j]=tran[j+1];
						tran[j+1]=t;
					}
		  		}
		  	}
		  	dprint(count,goodcount,dealcount);
  			break;
  			
  		//按价格降序	
  		case 2:
  			for(int i=0;i<goodcount;i++)
	  		{
  		  		for(int j=0;j<goodcount-i-1;j++)
  		  		{
  		  			if(tran[j].com.price<tran[j+1].com.price)
  		  			{
  					  	struct transaction t;
						t=tran[j];
						tran[j]=tran[j+1];
						tran[j+1]=t;
  					}
  		  		}
	  		}
	  		dprint(count,goodcount,dealcount);
  			break;
  			
  		default:
  			printf("输入错误，请重新输入\n");
  			system("pause");
  			break;
  	}
  	
	system("pause");
	system("cls");
	
	writedFile(dealcount);//写入文件 
	
	dm(count,goodcount,dealcount);//返回交易菜单 
}

//修改信息（一） 
void dealmodify_one(int count,int goodcount,int dealcount)
{
	int flag=0;//记录该交易信息是否存在 flag=1代表存在并修改 flag=0代表不存在
	
	//菜单选项 
	printf("****************************************************************************\n");
 	printf("查找方式：\n");
 	printf("1买家\n");
 	printf("2商品\n");
 	printf("****************************************************************************\n");	
	
	//获取用户输入 
	int ch;
 	scanf("%d",&ch);
	switch (ch)
 	{
 		//用买家信息查询并修改 
 		case 1: 
	 		system("cls");
			
			printf("请输入买家名称：");
  			char bname [20];
  			scanf("%s",bname);
   			
			   for(int i=0;i<dealcount;i++)
  		 	{
  		 		if(strcmp(tran[i].buyer.name,bname)==0)
  		 		{
  		 			flag=1; 
  		 			output(i);
  		 			dealmodify_two(i,count,goodcount); 
  		 		}
  		 	}
  			break;
 		
		//用商品信息查询并修改
		case 2: 
			system("cls");
	
	 		printf("请输入商品名称：");
   			char cname [20];
   			scanf("%s",cname);
   			
			for(int i=0;i<dealcount;i++)
  		 	{
  		 		if(strcmp(tran[i].com.cname,cname)==0)
  		 		{
  		 			flag=1;
  		 			output(i);
  		 			dealmodify_two(i,count,goodcount);
  		 		}
  		 	}
   			break;
	   			
 		default:
 			flag=2;//不输出结果语句 
 			printf("输入错误，请重新输入\n");
 			system("pause");
 			break;
 			
 	}
 	
	if(flag==0) printf("暂无相关交易记录\n");
	if(flag==1) printf("修改成功\n");
  	
	system("pause"); 
  	system("cls");
  	
	writedFile(dealcount);//写入文件 
  	
	dm(count,goodcount,dealcount);//返回交易菜单 
}

//修改信息（二） 
void dealmodify_two(int i,int count,int goodcount)
{
	int flag=0;//判断买家是否存在于系统 
	
	//菜单选项 
	printf("****************************************************************************\n");
 	printf("请输入要进行的操作：\n");
 	printf("1修改买家\n");
 	printf("2修改商品\n");
 	printf("****************************************************************************\n");
 	
 	//获取输入 
	int ch;	
 	scanf("%d",&ch);
	switch (ch)
 	{
 		//修改买家 
 		case 1:
 			printf("修改为：");
			char bn [20];
 			scanf("%s",bn);
 			for(int j=0;j<count;j++)
		 	{
		 		if(strcmp(stu[j].name,bn)==0)
		 		{
		 			tran[i].buyer=stu[j];
		 			flag=1;
		 		}
		 	}
		 	if(flag==0)printf("该买家不存在\n"); 
 			break;
 			
		//修改商品 	
	 	case 2:
 			printf("修改为："); 
			char cn [20];
 			scanf("%s",cn);
 			for(int j=0;j<goodcount;j++)
 		 	{
 		 		if(strcmp(com[j].cname,cn)==0)
 		 		{
 		 			tran[i].com=com[j];
 		 			flag=1; 
					for(int z=0;z<count;z++)
					{
						if(strcmp(com[j].sname,stu[z].name)==0)
						{
							tran[i].seller=stu[z];
						}
					} 		 				
 		 		}
 		 	}
 		 	if(flag==0)printf("该商品不存在\n");
 			break;
 			
 		default:
 			printf("输入错误，请重新输入\n");
 			system("pause");
 			break;
 	}
}
 
//交易文件保存 
void writedFile(int dealcount)
{
	FILE *fp=fopen("sdeal.txt","w");
	
	if( fp== NULL )
	{
		printf("fail to open\n");
		perror("fopen");
		exit(0);
	}
	
	fprintf(fp,"%d",dealcount);
	
	for(int i=0;i<dealcount;i++)
	{
		fwrite(&tran[i],sizeof(struct transaction),1,fp);
	}
	
	fclose(fp);	
	
	fp=NULL;
}

//交易文件读取 
int readdFile() 
{
	FILE *fp=fopen("sdeal.txt","r");
	
	if( fp==NULL )
	{
		printf("fail to open\n");
		exit(0);
	}
	
	int dealcount=0;
	fscanf(fp,"%d",&dealcount);
	
	for(int i=0;i<dealcount;i++)
	{
		fread(&tran[i],sizeof(struct transaction),1,fp);
	}
	
	fclose(fp);
	
	fp=NULL;
	
	return dealcount;
}
 
//交易子目录 
void dm(int count,int goodcount,int dealcount)
 {
    printf("****************************************************************************\n");
 	printf("交易信息\n");
 	printf("请输入要进行的操作：\n");
 	printf("1生成\n");
 	printf("2查找\n");
 	printf("3删除\n");
 	printf("4排序\n");
 	printf("5修改\n");
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
	  			create(count,goodcount,dealcount); 
	  			break;
	  			
	  		case 2:
	  			system("cls");
	  			dealsearch(count,goodcount,dealcount); 
	  			break;
	  			
	  		case 3:
	  			system("cls");
	  			dealdel(count,goodcount,dealcount);
	  			break;
	  			
	  		case 4:
	  			system("cls");
	  			dealsort(count,goodcount,dealcount);
	  			break;
	  			
	  		case 5:
	  			system("cls");
	  			dealmodify_one(count,goodcount,dealcount);
	  			break;
	  			
	  		case 6:
	  			system("cls");
				dprint(count,goodcount,dealcount);
				break;
				
	  		case 7: 
	 			system("cls");
	 			writedFile(dealcount);
	 		  	menu(count,goodcount,dealcount);//返回主菜单 
	 		  	break;
	 		  	
	  		default:
	  			printf("输入错误，请重新输入\n");
	  			flag=1; 
	  			break;
	  	}	
  	}
 }
