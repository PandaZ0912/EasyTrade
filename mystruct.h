#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//ѧ���ṹ�� 
struct student
{
	char name [20];//���� 
	
	char college [30];//ѧԺ 
	
	char class_[20];//�༶ 
	
	char num [10];//ѧ�� 
	
	char tel [20];//�绰 
	
};

//��Ʒ�ṹ�� 
struct commodity 
{
	int price;//�۸� 
	
	int amount;//���� 
	
	char cname [20];//��Ʒ���� 
	
	char sname [20];//���� 	
};

//���׽ṹ�� 
struct transaction
{
	struct student buyer;//��� 
	
	struct commodity com;//��Ʒ 
	
	struct student seller;//���� 
	
};


//�ṹ���������� 
extern struct student stu[50];//���ѧ����Ϣ 

extern struct commodity com[50];//�����Ʒ��Ϣ 

extern struct transaction tran[50];//��Ž�����Ϣ 


//������������

//������ 
extern void menu(int count,int goodcount,int dealcount);

//ѧ�� student.c�ļ� 
extern void writesFile(int count);

extern int readsFile();

extern void sprint(int count,int goodcount,int dealcount);

extern void insert(int count,int goodcount,int dealcount);

extern void del(int count,int goodcount,int dealcount);

extern void search(int count,int goodcount,int dealcount);

extern void modify(int count,int goodcount,int dealcount);

extern void studentmenu(int count,int goodcount,int dealcount);

//��Ʒ commodity.c�ļ� 
extern void writecFile(int goodcount);

extern int readcFile();

extern void on(int count,int goodcount,int dealcount); 

extern void down(int count,int goodcount,int dealcount);

extern void sort(int count,int goodcount,int dealcount);

extern void goodmodify(int count,int goodcount,int dealcount);

extern void goodsearch(int count,int goodcount,int dealcount);

extern void cprint(int count,int goodcount,int dealcount);

extern void commoditymenu(int count,int goodcount,int dealcount);

//���� information.c�ļ� 
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
