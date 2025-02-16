#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//学生结构体 
struct student
{
	char name [20];//姓名 
	
	char college [30];//学院 
	
	char class_[20];//班级 
	
	char num [10];//学号 
	
	char tel [20];//电话 
	
};

//商品结构体 
struct commodity 
{
	int price;//价格 
	
	int amount;//数量 
	
	char cname [20];//商品名称 
	
	char sname [20];//卖家 	
};

//交易结构体 
struct transaction
{
	struct student buyer;//买家 
	
	struct commodity com;//商品 
	
	struct student seller;//卖家 
	
};


//结构体数组声明 
extern struct student stu[50];//存放学生信息 

extern struct commodity com[50];//存放商品信息 

extern struct transaction tran[50];//存放交易信息 


//函数声明部分

//主函数 
extern void menu(int count,int goodcount,int dealcount);

//学生 student.c文件 
extern void writesFile(int count);

extern int readsFile();

extern void sprint(int count,int goodcount,int dealcount);

extern void insert(int count,int goodcount,int dealcount);

extern void del(int count,int goodcount,int dealcount);

extern void search(int count,int goodcount,int dealcount);

extern void modify(int count,int goodcount,int dealcount);

extern void studentmenu(int count,int goodcount,int dealcount);

//商品 commodity.c文件 
extern void writecFile(int goodcount);

extern int readcFile();

extern void on(int count,int goodcount,int dealcount); 

extern void down(int count,int goodcount,int dealcount);

extern void sort(int count,int goodcount,int dealcount);

extern void goodmodify(int count,int goodcount,int dealcount);

extern void goodsearch(int count,int goodcount,int dealcount);

extern void cprint(int count,int goodcount,int dealcount);

extern void commoditymenu(int count,int goodcount,int dealcount);

//交易 information.c文件 
extern void writedFile(int dealcount);

extern int readdFile();

extern void create(int count,int goodcount,int dealcount);

extern void dealmodify_one(int count,int goodcount,int dealcount);

extern void dealmodify_two(int i,int count,int goodcount); 

extern void dealsearch(int count,int goodcount,int dealcount);

extern void dealdel(int count,int goodcount,int dealcount);

extern void dealsort(int count,int goodcount,int dealcount);

extern void output(int i);

extern void dprint(int count,int goodcount,int dealcount);

extern void dm(int count,int goodcount,int dealcount);
