#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct student stu[50];

//����ѧ����Ϣ 
void insert(int count,int goodcount,int dealcount)
{
	printf("������ѧ����ѧ�ţ�");
	scanf("%s",stu[count].num);
	
	printf("������ѧ����������");
	scanf("%s",stu[count].name);
	
	printf("������ѧ����ѧԺ��");
	scanf("%s",stu[count].college);
	
	printf("������ѧ���İ༶��");
	scanf("%s",stu[count].class_);
	
	printf("������ѧ���ĵ绰��");
	scanf("%s",stu[count].tel);	
	
	printf("\n");
	count++;
	printf("��ӳɹ���\n");
	
	system("pause");
	system("cls");
	
	writesFile(count);//д���ļ� 
	studentmenu(count,goodcount,dealcount);//���ز˵� 
}

//ɾ��ѧ����Ϣ (ʹ��������ѧ��ɾ��)
void del(int count,int goodcount,int dealcount)
{   
	int flag=0;//��¼��ѧ����Ϣ�Ƿ���� flag=1������ڲ�ɾ�� flag=0��������
	
	char a[20];//��¼��������� 
	char b[10];//��¼�����ѧ�� 
	
	printf("****************************************************************************\n");
 	printf("ʹ��ɾ����ʽ��\n");
 	printf("1������ɾ��\n");
 	printf("2��ѧ��ɾ��\n");
 	printf("****************************************************************************\n");
 	
	int ch; 
  	scanf("%d",&ch);
	switch (ch)
  	{
  		case 1:
		  	printf("��������Ҫɾ����ѧ����������");
		  	scanf("%s",a);
		  	for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].name,a)==0)//Ѱ������������Ƿ���� 
		  		{
		  		    flag=1;
		  		    //���Ǳ�ɾ������ 
		  		    for(int j=i;j<count-1;j++)
		  		    {
		  		   		stu[j]=stu[j+1];
		  		    }
		  		}
		  		if(flag==1)break;
		  	}
  		    break;
  		    
  		case 2:
		  	printf("��������Ҫɾ����ѧ����ѧ�ţ�");
		  	scanf("%s",b);
		  	for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].num,b)==0)//Ѱ�������ѧ���Ƿ���� 
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
  			printf("�����������������\n");
  			flag=2;//����������� 
  			break;
  	}
  	
	if(flag==0) printf("��ѧ��������\n");
	if(flag==1) 
	{
		printf("ɾ���ɹ�\n");
		count--;
	}
	
	system("pause"); 
	system("cls");
	
	writesFile(count);//д���ļ� 
	studentmenu(count,goodcount,dealcount);//���ز˵� 
}

//����ѧ����Ϣ (ʹ��������ѧ�Ų���)
void search(int count,int goodcount,int dealcount)
{
	int flag=0; //��¼��ѧ����Ϣ�Ƿ���� flag=1������� flag=0�������� 	
	
	printf("****************************************************************************\n");
 	printf("���ҷ�ʽ��\n");
 	printf("1����������\n");
 	printf("2��ѧ�Ų���\n");
 	printf("****************************************************************************\n");
 	
	int ch;
  	scanf("%d",&ch);
	switch (ch)
  	{
  		case 1:
  			system("cls");
  		    
			printf("��������Ҫ���ҵ�ѧ����������");
			char a_name[20];
   		  	scanf("%s",a_name);
   		  	
			for(int i=0;i<count;i++)
   		  	{
   		  		if(strcmp(stu[i].name,a_name)==0)
   		  		{
   		  			flag=1;
   		  			printf("****************************************************************************\n");
					printf("����:%s\tѧԺ:%s\t�༶:%s\tѧ��:%s\t�绰:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,
																			stu[i].num,stu[i].tel);
   		  			printf("****************************************************************************\n");
   		  		}
   		  	}
     			break;
  			break;
  	
	  	case 2:
  			system("cls");
  			
			printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
			char a_num[10];
		  	scanf("%s",a_num);
		  	
			for(int i=0;i<count;i++)
		  	{
		  		if(strcmp(stu[i].num,a_num)==0)
		  		{
		  			flag=1;
		  			printf("****************************************************************************\n");
  					printf("����:%s\tѧԺ:%s\t�༶:%s\tѧ��:%s\t�绰:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,
					  														stu[i].num,stu[i].tel);
     		  		printf("****************************************************************************\n");
		  		}
		  	}
  			break;
  		
		default:
  			printf("�����������������\n");
  			flag=2;//����������� 
  			break;
  	}
  	
	if(flag==0) printf("��ѧ��������!\n");
	
	system("pause"); 
	system("cls");
	
	writesFile(count);//д���ļ� 
	studentmenu(count,goodcount,dealcount);//���ز˵� 
}

//�޸�ѧ����Ϣ (ʹ��������ѧ���޸ģ� 
void modify(int count,int goodcount,int dealcount)
{
	int flag=0; //��¼��ѧ����Ϣ�Ƿ���� flag=1������ڲ��޸� flag=0�������� 
	int x;//��Ŵ��޸�ѧ������Ϣ���������±� 
	
	char a[20];//��Ҫ�޸ĵ�ѧ�������� 
	char b[20];//��Ҫ�޸ĵ�ѧ����ѧ�� 

	printf("****************************************************************************\n");
 	printf("ʹ���޸ķ�ʽ��\n");
 	printf("1�������޸�\n");
 	printf("2��ѧ���޸�\n");
 	printf("****************************************************************************\n");
 
 	int ch;
  	scanf("%d",&ch);
  	switch (ch)
  	{
  		case 1:
		  	printf("��������Ҫ�޸ĵ�ѧ����������");
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
		  	printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
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
  			printf("�����������������\n");
  			flag=2;//����������� 
  			break;
  	}

	if(flag==0) printf("��ѧ��������\n");
	if(flag==1)
	{
	
		printf("****************************************************************************\n");
	 	printf("������Ҫ���еĲ�����\n");
	 	printf("1�޸�ѧ��\n");
	 	printf("2�޸�ѧԺ\n");
	 	printf("3�޸İ༶\n");
	 	printf("4�޸ĵ绰\n");
	 	printf("5�޸�����\n");
	 	printf("****************************************************************************\n");
	  
	  	int ch;
	 	scanf("%d",&ch);
	 	switch (ch)
	 	{
	 		case 1:
	 			printf("�޸�Ϊ��"); 
	 			char num[20];
	 			scanf("%s",num);
	 			strcpy(stu[x].num,num);
	 			printf("�޸ĳɹ�\n");
	 			break;
	 			
	 		case 2:
	 			printf("�޸�Ϊ��"); 
	 			char college [30];
	 			scanf("%s",college);
	 			strcpy(stu[x].college,college);
	 			printf("�޸ĳɹ�\n");
	 			break;
	 			
	 		case 3:
	 			printf("�޸�Ϊ��"); 
	 			char class_ [20];
				scanf("%s",class_);
	 			strcpy(stu[x].class_,class_);
	 			printf("�޸ĳɹ�\n");
	 			break;
	 			
	 		case 4:
	 			printf("�޸�Ϊ��"); 
	 			char tel [20];
	 			scanf("%s",tel);
	 			strcpy(stu[x].tel,tel);
	 			printf("�޸ĳɹ�\n");
	 			break;
	 		case 5:
	  			printf("�޸�Ϊ��"); 
	  			char name[20]; 
	  			scanf("%s",name);
	  			strcpy(stu[x].name,name);
	  			printf("�޸ĳɹ�\n");
	  			break;
	
	 		default:
	 			printf("�����������������\n");
	 			system("pause");
	 			break;
	 	}
	}
 	system("pause"); 
	system("cls");

	writesFile(count);//д���ĵ� 
 	studentmenu(count,goodcount,dealcount);//���ز˵� 
}

//���ѧ����Ϣ (����)
void sprint(int count,int goodcount,int dealcount)
{
	if(count==0) printf("����ѧ����Ϣ\n");

	for(int i=0;i<count;i++)
	{
		printf("****************************************************************************\n");
		printf("����:%s\tѧԺ:%s\t�༶:%s\tѧ��:%s\t�绰:%s\t\n",stu[i].name,stu[i].college,stu[i].class_,stu[i].num,stu[i].tel);
		printf("****************************************************************************\n");
	}
	
	system("pause"); 
	system("cls");

	writesFile(count);//д���ĵ� 
	studentmenu(count,goodcount,dealcount);//���ز˵� 
} 

//ѧ���ļ����� 
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

//ѧ���ļ���ȡ 
int readsFile()
{
	FILE *fp=fopen("student.txt","r");

	if( fp==NULL )
	{
		printf("fail to open\n");
		exit(0);
	}
	
	int count=0;//ѧ������ 
	fscanf(fp,"%d",&count);

	for(int i=0;i<count;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
	}
	
	fclose(fp);

	fp=NULL;

	return count;
}

//ѧ����Ŀ¼ 
void studentmenu(int count,int goodcount,int dealcount)
{
	int flag=1;//flag==1�������������Ҫ��������
	 
	printf("****************************************************************************\n");
	printf("ѧ����Ϣ\n");
	printf("������Ҫ���еĲ�����\n");
	printf("1����\n");
	printf("2ɾ��\n");
	printf("3����\n");
	printf("4�޸�\n");
	printf("5���\n");
	printf("6����\n");
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
	 			menu(count,goodcount,dealcount);//�������˵� 
	 			break;

	 		default:
	 			printf("�����������������\n");
	 			flag=1;
	 			break;
	 	}	
 	}
}
