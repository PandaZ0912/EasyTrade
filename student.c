#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct student stu[50];

//插入学生信息 
void insert(int count,int goodcount,int dealcount)
{
	printf("请输入学生的学号：");
	scanf("%s",stu[count].num);
	
	printf("请输入学生的姓名：");
	scanf("%s",stu[count].name);
	
	printf("请输入学生的学院：");
	scanf("%s",stu[count].college);
	
	printf("请输入学生的班级：");
	scanf("%s",stu[count].class_);
	
	printf("请输入学生的电话：");
	scanf("%s",stu[count].tel);	
	
	printf("\n");
	count++;
	printf("添加成功！\n");
	
	system("pause");
	system("cls");
	
	writesFile(count);//写入文件 
	studentmenu(count,goodcount,dealcount);//返回菜单 
}

//删除学生信息 (使用姓名或学号删除)
void del(int count,int goodcount,int dealcount)
{   
	int flag=0;//记录该学生信息是否存在 flag=1代表存在并删除 flag=0代表不存在
	
	char a[20];//记录输入的姓名 
	char b[10];//记录输入的学号 
	
	printf("****************************************************************************\n");
 	printf("使用删除方式：\n");
 	printf("1用姓名删除\n");
 	printf("2用学号删除\n");
 	printf("****************************************************************************\n");
 	
	int ch; 
  	scanf("%d",&ch);
	switch (ch)
  	{
  		case 1:
		  	printf("请输入需要删除的学生的姓名：");
		  	scanf("%s",a);
		  	for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].name,a)==0)//寻找输入的姓名是否存在 
		  		{
		  		    flag=1;
		  		    //覆盖被删除对象 
		  		    for(int j=i;j<count-1;j++)
		  		    {
		  		   		stu[j]=stu[j+1];
		  		    }
		  		}
		  		if(flag==1)break;
		  	}
  		    break;
  		    
  		case 2:
		  	printf("请输入需要删除的学生的学号：");
		  	scanf("%s",b);
		  	for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].num,b)==0)//寻找输入的学号是否存在 
		  		{
		  		   flag=1;
		  		   
		  		   for(int j=i;j<count-1;j++)
		  		   {
		  		   	 stu[j]=stu[j+1];
		  		   }
		  		}
		  		if(flag==1)break;
		  	}
  			break;
  			
  		default:
  			printf("输入错误，请重新输入\n");
  			flag=2;//不输出结果语句 
  			break;
  	}
  	
	if(flag==0) printf("该学生不存在\n");
	if(flag==1) 
	{
		printf("删除成功\n");
		count--;
	}
	
	system("pause"); 
	system("cls");
	
	writesFile(count);//写入文件 
	studentmenu(count,goodcount,dealcount);//返回菜单 
}

//查找学生信息 (使用姓名或学号查找)
void search(int count,int goodcount,int dealcount)
{
	int flag=0; //记录该学生信息是否存在 flag=1代表存在 flag=0代表不存在 	
	
	printf("****************************************************************************\n");
 	printf("查找方式：\n");
 	printf("1按姓名查找\n");
 	printf("2按学号查找\n");
 	printf("****************************************************************************\n");
 	
	int ch;
  	scanf("%d",&ch);
	switch (ch)
  	{
  		case 1:
  			system("cls");
  		    
			printf("请输入需要查找的学生的姓名：");
			char a_name[20];
   		  	scanf("%s",a_name);
   		  	
			for(int i=0;i<count;i++)
   		  	{
   		  		if(strcmp(stu[i].name,a_name)==0)
   		  		{
   		  			flag=1;
   		  			printf("****************************************************************************\n");
					printf("姓名:%s\t学院:%s\t班级:%s\t学号:%s\t电话:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,
																			stu[i].num,stu[i].tel);
   		  			printf("****************************************************************************\n");
   		  		}
   		  	}
     			break;
  			break;
  	
	  	case 2:
  			system("cls");
  			
			printf("请输入需要查找的学生的学号：");
			char a_num[10];
		  	scanf("%s",a_num);
		  	
			for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].num,a_num)==0)
		  		{
		  			flag=1;
		  			printf("****************************************************************************\n");
  					printf("姓名:%s\t学院:%s\t班级:%s\t学号:%s\t电话:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,
					  														stu[i].num,stu[i].tel);
     		  		printf("****************************************************************************\n");
		  		}
		  	}
  			break;
  		
		default:
  			printf("输入错误，请重新输入\n");
  			flag=2;//不输出结果语句 
  			break;
  	}
  	
	if(flag==0) printf("该学生不存在!\n");
	
	system("pause"); 
	system("cls");
	
	writesFile(count);//写入文件 
	studentmenu(count,goodcount,dealcount);//返回菜单 
}

//修改学生信息 (使用姓名或学号修改） 
void modify(int count,int goodcount,int dealcount)
{
	int flag=0; //记录该学生信息是否存在 flag=1代表存在并修改 flag=0代表不存在 
	int x;//存放待修改学生的信息所在数组下标 
	
	char a[20];//需要修改的学生的姓名 
	char b[20];//需要修改的学生的学号 

	printf("****************************************************************************\n");
 	printf("使用修改方式：\n");
 	printf("1用姓名修改\n");
 	printf("2用学号修改\n");
 	printf("****************************************************************************\n");
 
 	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		case 1:
		  	printf("请输入需要修改的学生的姓名：");
		  	scanf("%s",a);
		  	for(int i=0;i<count;i++)
	  		{
	  			if(strcmp(stu[i].name,a)==0)
	  			{
	  				x=i;
	  				flag=1;
	  			}
	  		}
  		    break;
 
  		case 2:
		  	printf("请输入需要修改的学生的学号：");
  		  	scanf("%s",b);
  		  	for(int i=0;i<count;i++)
	  		{
	  			if(strcmp(stu[i].num,b)==0)
	  			{
	  				x=i;
	  				flag=1;
	  			}
	  		}
  			break;
 
  		default:
  			printf("输入错误，请重新输入\n");
  			flag=2;//不输出结果语句 
  			break;
  	}

	if(flag==0) printf("该学生不存在\n");
	if(flag==1)
	{
	
		printf("****************************************************************************\n");
	 	printf("请输入要进行的操作：\n");
	 	printf("1修改学号\n");
	 	printf("2修改学院\n");
	 	printf("3修改班级\n");
	 	printf("4修改电话\n");
	 	printf("5修改姓名\n");
	 	printf("****************************************************************************\n");
	  
	  	int ch;
	 	scanf("%d",&ch);
	 	switch (ch)
	 	{
	 		case 1:
	 			printf("修改为："); 
	 			char num[20];
	 			scanf("%s",num);
	 			strcpy(stu[x].num,num);
	 			printf("修改成功\n");
	 			break;
	 			
	 		case 2:
	 			printf("修改为："); 
	 			char college [30];
	 			scanf("%s",college);
	 			strcpy(stu[x].college,college);
	 			printf("修改成功\n");
	 			break;
	 			
	 		case 3:
	 			printf("修改为："); 
	 			char class_ [20];
				scanf("%s",class_);
	 			strcpy(stu[x].class_,class_);
	 			printf("修改成功\n");
	 			break;
	 			
	 		case 4:
	 			printf("修改为："); 
	 			char tel [20];
	 			scanf("%s",tel);
	 			strcpy(stu[x].tel,tel);
	 			printf("修改成功\n");
	 			break;
	 		case 5:
	  			printf("修改为："); 
	  			char name[20]; 
	  			scanf("%s",name);
	  			strcpy(stu[x].name,name);
	  			printf("修改成功\n");
	  			break;
	
	 		default:
	 			printf("输入错误，请重新输入\n");
	 			system("pause");
	 			break;
	 	}
	}
 	system("pause"); 
	system("cls");

	writesFile(count);//写入文档 
 	studentmenu(count,goodcount,dealcount);//返回菜单 
}

//输出学生信息 (所有)
void sprint(int count,int goodcount,int dealcount)
{
	if(count==0) printf("暂无学生信息\n");

	for(int i=0;i<count;i++)
	{
		printf("****************************************************************************\n");
		printf("姓名:%s\t学院:%s\t班级:%s\t学号:%s\t电话:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,stu[i].num,stu[i].tel);
		printf("****************************************************************************\n");
	}
	
	system("pause"); 
	system("cls");

	writesFile(count);//写入文档 
	studentmenu(count,goodcount,dealcount);//返回菜单 
} 

//学生文件保存 
void writesFile(int count)
{
	FILE *fp=fopen("student.txt","w");

	if( fp== NULL )
	{
		printf("fail to open\n");
		perror("fopen");
		exit(0);
	}
	
	fprintf(fp,"%d",count);

	for(int i=0;i<count;i++)
	{
		fwrite(&stu[i],sizeof(struct student),1,fp);
	}
	
	fclose(fp);	

	fp=NULL;
	
}

//学生文件读取 
int readsFile()
{
	FILE *fp=fopen("student.txt","r");

	if( fp==NULL )
	{
		printf("fail to open\n");
		exit(0);
	}
	
	int count=0;//学生人数 
	fscanf(fp,"%d",&count);

	for(int i=0;i<count;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
	}
	
	fclose(fp);

	fp=NULL;

	return count;
}

//学生子目录 
void studentmenu(int count,int goodcount,int dealcount)
{
	int flag=1;//flag==1代表输入错误，需要重新输入
	 
	printf("****************************************************************************\n");
	printf("学生信息\n");
	printf("请输入要进行的操作：\n");
	printf("1插入\n");
	printf("2删除\n");
	printf("3查找\n");
	printf("4修改\n");
	printf("5输出\n");
	printf("6返回\n");
	printf("****************************************************************************\n");

	while(flag==1) 
	{
		int ch;
	 	scanf("%d",&ch);

	 	switch (ch)
	 	{
	 		case 1:
	 			system("cls");
	 			insert(count,goodcount,dealcount);
	 			break;

	 		case 2:
	 			system("cls");
	 			del(count,goodcount,dealcount);
	 			break;

	 		case 3:
	 			system("cls");
	 			search(count,goodcount,dealcount);
	 			break;

	 		case 4:
	 			system("cls");
	 			modify(count,goodcount,dealcount);
	 			break;

	 		case 5:
	 			system("cls");
				sprint(count,goodcount,dealcount);
	 			break;

	 		case 6: 
				system("cls");
				writesFile(count);
	 			menu(count,goodcount,dealcount);//返回主菜单 
	 			break;

	 		default:
	 			printf("输入错误，请重新输入\n");
	 			flag=1;
	 			break;
	 	}	
 	}
}
