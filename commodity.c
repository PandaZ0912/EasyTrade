#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct commodity com[50];

//�ϼ� 
void on(int count,int goodcount,int dealcount)
{
	int flag=0;//��¼�����Ƿ���� 
	
	printf("��������Ʒ��Ϣ��\n");
	system("pause");
	
	printf("��������Ʒ�����ƣ�");
	scanf("%s",com[goodcount].cname);
	
	printf("��������Ʒ�ļ۸�");
	scanf("%d",&com[goodcount].price);
	
	printf("��������Ʒ��������");
	scanf("%d",&com[goodcount].amount);
	
	printf("��������Ʒ�����ң�");
	scanf("%s",com[goodcount].sname);
	
	////�ж��û��Ƿ������ϵͳ��
	for(int j=0;j<count;j++)
	{
		if(strcmp(stu[j].name,com[goodcount].sname)==0)
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		printf("�ϼܳɹ�\n");
		goodcount++;
	}
	else printf("���Ҳ�����\n�ϼ�ʧ��\n");
	
	system("pause"); 
	system("cls");
	
	writecFile(goodcount);//д���ļ�
	
	commoditymenu(count,goodcount,dealcount);//������Ʒ�˵� 
}

//�¼� 
void down(int count,int goodcount,int dealcount)
{
	int flag=0;//��¼����Ʒ��Ϣ�Ƿ���� flag=1������ڲ��¼� flag=0��������
	
	char cname [20];
	
	printf("�������¼ܵ���Ʒ����:");
	scanf("%s",cname);
	
	for(int i=0;i<goodcount;i++)
	{
		if(strcmp(com[i].cname,cname)==0)
		{
		   flag=1; //��Ʒ���� 
		   for(int j=i;j<goodcount-1;j++)
		   {
		   	 com[j]=com[j+1];
		   }
		}
		if(flag==1)break;
	}
	
	if(flag==0) printf("����Ʒ������\n");
	if(flag==1) 
		{
			printf("�¼ܳɹ�\n");
			goodcount--;
		}
		
	system("pause");
	system("cls");
	
	writecFile(goodcount);//д���ļ� 
	
	commoditymenu(count,goodcount,dealcount);//������Ʒ�˵� 
}

//���� (���۸�����)
void sort(int count,int goodcount,int dealcount) 
{
	//�ж�ϵͳ���Ƿ������Ʒ��Ϣ
	if(goodcount==0)printf("������Ʒ��Ϣ\n");
	
	//�˵�ѡ�� 
	printf("****************************************************************************\n");
 	printf("����ʽ��\n");
 	printf("1���۸�����\n");
 	printf("2���۸���\n");
 	printf("****************************************************************************\n");
 	
 	//��ȡ�û����� 
 	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		case 1:
  			//���۸�����
  		    for(int i=0;i<goodcount;i++)
		  	{
		  		for(int j=0;j<goodcount-i-1;j++)
		  		{
		  			//�Ƚ���Ʒ�۸�߶�
		  			if(com[j].price>com[j+1].price)
		  			{
					  	struct commodity t;//��ʱ�洢��Ϣ
						t=com[j];
						com[j]=com[j+1];
						com[j+1]=t;
					}
		  		}
		  	}
		  	cprint(count,goodcount,dealcount);//������ 
  			break;
  			
  		case 2:
  			//���۸���
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
  			printf("�����������������\n");
  			system("pause");
  			break;
  	}
  	
	system("pause");
	system("cls");
	
	writecFile(goodcount);// д���ļ� 
	
	commoditymenu(count,goodcount,dealcount);//������Ʒ�˵� 
}

//�޸� 
void goodmodify(int count,int goodcount,int dealcount)
{
	int price;//����޸�Ϊ�ļ۸� 
	int amount;//����޸�Ϊ������ 
	char sname [20];//����޸�Ϊ������ 
	char cname [20];//����޸�Ϊ������ 
	char modi [20];//���ڲ�����Ʒ
	
	int x;//��Ŵ��޸���Ʒ����Ϣ���������±�
	
	int flag=0;//��¼����Ʒ��Ϣ�Ƿ���� flag=1������ڲ��޸� flag=0��������
	
	 //������Ʒ 
	printf("��������Ҫ�޸ĵ���Ʒ������:");
	scanf("%s",modi);
	for(int i=0;i<goodcount;i++)
	{
		if(strcmp(com[i].cname,modi)==0)
		{
			flag=1;//�ҵ���Ʒ 
			
			x=i;//��¼�ҵ�����Ʒ 
			
			printf("****************************************************************************\n");
		  	printf("������Ҫ���еĲ�����\n");
		  	printf("1�޸�����\n");
		  	printf("2�޸ļ۸�\n");
		  	printf("3�޸�����\n");
		  	printf("4�޸�����\n");
		  	printf("****************************************************************************\n");
		  	
		  	int ch;
		  	scanf("%d",&ch);
		  	switch (ch)
		  	{
		  		case 1:
		  			printf("�޸�Ϊ��"); 
		  			scanf("%s",cname);
		  			strcpy(com[x].cname,cname);
		  			break;
		  		case 2:
		  			printf("�޸�Ϊ��"); 
		  			scanf("%d",&price);
		  			com[x].price=price;
		  			break;
		  		case 3:
		  			printf("�޸�Ϊ��"); 
		  			scanf("%d",&amount);
		  			com[x].amount=amount;
		  			break;
		  		case 4:
		  			printf("�޸�Ϊ��"); 
		  			scanf("%s",sname);
		  			strcpy(com[x].sname,sname);
		  			break;
		  		default:
		  			flag=2;//����������� 
		  			printf("�����������������\n");
		  			system("pause");
		  			break;
			  	}
		}
	}
	
 	if(flag==0) printf("����Ʒ������\n");
 	if(flag==1) 
 		{
 			printf("�޸ĳɹ�\n");
 		}
 		
 	system("pause");
 	system("cls");
 	
 	writecFile(goodcount);//д���ļ� 
 	
	commoditymenu(count,goodcount,dealcount);//������Ʒ�˵� 
}

//���� 
void goodsearch(int count,int goodcount,int dealcount)
{
	
	char s [20];
	int flag=0;//��¼����Ʒ��Ϣ�Ƿ���� flag=1������� flag=0��������
	
	printf("****************************************************************************\n");
 	printf("���ҷ�ʽ��\n");
 	printf("1�����Ʋ���\n");
 	printf("2�����Ҳ���\n");
 	printf("****************************************************************************\n");	
 	
	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		//ͨ�����Ʋ��� 
  		case 1:
  		    printf("��������Ҫ���ҵ���Ʒ�����ƣ�");
		 	scanf("%s",s);
		 	for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(com[i].cname,s)==0)
		 		{
		 			flag=1;
		 			printf("****************************************************************************\n");
					printf("����:%s\t�۸�:%d\t����:%d\t����:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
					printf("****************************************************************************\n");	
		 		}
		 	}
  			break;
  			
  		//ͨ�����Ҳ��� 
  		case 2:
  			printf("��������Ҫ���ҵ���Ʒ�����ң�");
		 	scanf("%s",s);
		 	for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(com[i].sname,s)==0)
		 		{
		 			flag=1;
		 			printf("****************************************************************************\n");
		 			printf("����:%s\t�۸�:%d\t����:%d\t����:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
		 			printf("****************************************************************************\n");
		 		}
		 	}	
  			break;
  			
  		default:
  			printf("�����������������\n");
  			flag=2;
  			break;
  	}
  	
	if(flag==0)printf("��Ʒ������\n");
	
	system("pause");
	system("cls");
	
	commoditymenu(count,goodcount,dealcount);//������Ʒ�˵� 
}

//��� 
void cprint(int count,int goodcount,int dealcount)
{
	
	if(goodcount==0) printf("������Ʒ��Ϣ\n");
	
	for(int i=0;i<goodcount;i++)
	{
		printf("****************************************************************************\n");
		printf("����:%s\t�۸�:%d\t����:%d\t����:%s\t\n",com[i].cname,com[i].price,com[i].amount,com[i].sname);
		printf("****************************************************************************\n");
	}
	
	system("pause"); 
	system("cls");
	
	commoditymenu(count,goodcount,dealcount);
} 

//�ļ����� 
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

//�ļ���ȡ 
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

//��Ʒ��Ŀ¼ 
void commoditymenu(int count,int goodcount,int dealcount)
{
    printf("****************************************************************************\n");
	printf("��Ʒ��Ϣ\n");
	printf("������Ҫ���еĲ�����\n");
	printf("1�ϼ�\n");
	printf("2�¼�\n");
	printf("3����\n");
	printf("4�޸�\n");
	printf("5����\n");
	printf("6���\n");
	printf("7����\n");
	printf("****************************************************************************\n");
	int flag=1;//flag==1�������������Ҫ�������� 
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
			  	menu(count,goodcount,dealcount);//�������˵� 
			  	break;
	 		default:
	 			printf("�����������������\n");
	 			flag=1; 
	 			break;
	 	}
 	}
 	
}
