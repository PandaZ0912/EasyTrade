#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

//������ 
int main() 
{
	int count=0;//�Ѽ�¼��ѧ������
	int goodcount=0;//�Ѽ�¼����Ʒ��
	int dealcount=0;//�Ѽ�¼�Ľ����� 
	FILE *fp;
	if((fp=fopen("student.txt","r"))==NULL) writesFile(count);
	if((fp=fopen("commodity.txt","r"))==NULL) writecFile(goodcount);
	if((fp=fopen("sdeal.txt","r"))==NULL) writedFile(dealcount);
	count=readsFile();
	goodcount=readcFile();
	dealcount=readdFile();
	menu(count,goodcount,dealcount);//����˵� 
	return 0;
}

//���˵� 
void menu(int count,int goodcount,int dealcount)
{
	printf("****************************************************************************\n");
	printf("                      ��ӭ����У԰������Ʒ���׹���ϵͳ                      \n");
	printf("                            ������Ҫ���еĲ�����                            \n");
	printf("                              1ѧ��������Ϣ                                 \n");
	printf("                              2������Ʒ��Ϣ                                 \n");
	printf("                              3������Ϣ                                     \n");
	printf("                              4�˳�ϵͳ                                     \n");
	printf("****************************************************************************\n");
	int flag=1;//flag==1�������������Ҫ�������� 
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
				 printf("�˳��ɹ�\n");
				 exit(0); 
				 break;		
			default:
				printf("�����������������\n");
				flag=1;
				break;
		}
	}
}


 
