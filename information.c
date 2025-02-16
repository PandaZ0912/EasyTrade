#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

struct transaction tran[50];

//����
void create(int count,int goodcount,int dealcount)
{
	int flag1=0;//��¼����Ƿ���� 
	int flag2=0;//��¼��Ʒ�Ƿ����
	 
	char bname [20];//��¼������� 
	char cname [20];//��¼��Ʒ���� 
	
	printf("��������ң�");
	scanf("%s",bname);
	
	printf("��������Ʒ���ƣ�");
	scanf("%s",cname);
	
	//�ж��û��Ƿ������ϵͳ�� 
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
		printf("��Ҳ�����\n����ʧ��");
	}
	
	//��Ҵ��ڣ���һ���ж���Ʒ�Ƿ������ϵͳ 
	else
	{
		for(int i=0;i<goodcount;i++)
		{
			if(strcmp(com[i].cname,cname)==0)//�ж���Ʒ�Ƿ���� 
			{
				if(com[i].amount==0) flag2=2;//�ж���Ʒ�Ƿ��п�� 
				
				else
				{
					flag2=1;
									
					com[i].amount--;
					
					tran[dealcount].com=com[i];
				}
				
				
				for(int j=0;j<count;j++)//��Ʒ����ʱ¼��ϵͳ 
				{
					if(strcmp(stu[j].name,com[i].sname)==0)
					{
						tran[dealcount].seller=stu[j]; 
					}
				}
			}
		}
		
		if(flag2==2)printf("��Ʒ������\n����ʧ��\n");//��Ʒ����ʱ 
		if(flag2==0)printf("��Ʒ������\n����ʧ��\n");//��Ʒ������ʱ 

	}
	
	if((flag1==1)&&(flag2==1))
	{
		dealcount++;
		
		printf("���ɳɹ�\n");
	}
	
	system("pause"); 
	system("cls");
	
	writedFile(dealcount);//д���ļ� 
	
	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//�������������Ϣ 
void output(int i)
{
	
	printf("****************************************************************************\n");
 	printf("�˵�%d��\n",i+1);
 	printf("****************************************************************************\n");
 	
	printf("�����Ϣ\n");
	printf("����:%s\tѧ��:%s\tѧԺ:%s\t�༶:%s\t�绰:%s\t\n",tran[i].buyer.name,tran[i].buyer.num,tran[i].buyer.college,
															tran[i].buyer.class_,tran[i].buyer.tel);
															
	printf("��Ʒ��Ϣ\n");
	printf("����:%s\t�۸�:%d\t����:%s\t\n",tran[i].com.cname,tran[i].com.price,tran[i].com.sname);
	
	printf("������Ϣ\n"); 
	printf("����:%s\tѧ��:%s\tѧԺ:%s\t�༶:%s\t�绰:%s\t\n",tran[i].seller.name,tran[i].seller.num,tran[i].seller.college,
															tran[i].seller.class_,tran[i].seller.tel);
} 

//���ȫ��������Ϣ 
void dprint(int count,int goodcount,int dealcount)
{
	if(dealcount==0) printf("���޽��׼�¼\n");
	
	for(int i=0;i<dealcount;i++)
	{
		output(i);
	}
  	
	system("pause"); 
  	system("cls");
  	
	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//����
void dealsearch(int count,int goodcount,int dealcount)
 {
	int flag=0;//��¼�ý�����Ϣ�Ƿ���� flag=1������� flag=0�������� 
	
	//����˵�ѡ�� 
	printf("****************************************************************************\n");
 	printf("���ҷ�ʽ��\n");
 	printf("1���\n");
 	printf("2��Ʒ\n");
 	printf("3����\n");
 	printf("****************************************************************************\n");
 	
	 //��ȡ�û�ѡ�� 
 	int ch;
 	scanf("%d",&ch);
 	switch (ch)
 	{
 		//ͨ��������� 
 		case 1:
 			
 			printf("������������ƣ�");
			char bname [20];
			scanf("%s",bname);
 			
			 for(int i=0;i<dealcount;i++)
		 	{
		 		if(strcmp(tran[i].buyer.name,bname)==0)//�ж��Ƿ���� 
		 		{
		 			flag=1;
		 			output (i);//�����Ϣ 
		 		}
		 	}
 			break;
 		
		//ͨ����Ʒ����	
 		case 2:
 	
 			printf("��������Ʒ���ƣ�");
 			char cname [20];
 			scanf("%s",cname);
 			
			 for(int i=0;i<dealcount;i++)
		 	{
		 		if(strcmp(tran[i].com.cname,cname)==0)//�ж��Ƿ���� 
		 		{
		 			flag=1;
		 			output (i);//�����Ϣ 
		 		}
		 	}
 			break;
 			
 		//ͨ����������	
 		case 3:
 			
 			printf("�������������ƣ�");
 			char sname [20];
			scanf("%s",sname);
 			
			 for(int i=0;i<goodcount;i++)
		 	{
		 		if(strcmp(tran[i].seller.name,sname)==0)//�ж��Ƿ���� 
		 		{
		 			flag=1;
		 			output (i);//�����Ϣ 
		 		}
		 	}
 			break;
 			
 		default:
 			flag=2;//����������� 
 			printf("�����������������\n");
 			system("pause");
 			break;
 	}
 	
 	//����ʧ�� 
 	if(flag==0) printf("���޸ý���\n");

	system("pause"); 
 	system("cls");
 	
 	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//ɾ��
void dealdel(int count,int goodcount,int dealcount)
{
	int flag=0;//��¼�ý�����Ϣ�Ƿ���� flag=1������� flag=0�������� 
	
	printf("������������ƣ�");
	char bname [20];
	scanf("%s",bname);
	
	printf("��������Ʒ���ƣ�");
	char cname [20];
	scanf("%s",cname);
	
	printf("�������������ƣ�");
	char sname [20];
	scanf("%s",sname);
	
	for(int i=0;i<dealcount;i++)
 	{
 		if((strcmp(tran[i].buyer.name,bname)==0)&&(strcmp(tran[i].com.cname,cname)==0)&&(strcmp(tran[i].seller.name,sname)==0))
 		{	  
		    //��Ʒ������1 
			for(int j=0;j<goodcount;j++)
			{
				if((strcmp(cname,com[j].cname)==0)&&(strcmp(sname,com[j].sname)==0))
				{
					com[j].amount++;
				}
			} 
			
			//ɾ���ý��׼�¼ 	
   			for(int j=i;j<dealcount-1;j++)
   		    {
   		   	  tran[j]=tran[j+1];
   		    }
 			dealcount--;//������Ϣ����-1 
 			 
			flag=1; 		   				
 		}
 	}
 	
 	if(flag==0) printf("���޸ý���\n");
 	if(flag==1) printf("ɾ���ɹ�\n");
  	
	system("pause"); 
  	system("cls");
  	
	writedFile(dealcount);//д���ļ� 
	
  	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//����
void dealsort(int count,int goodcount,int dealcount)
{
	//�ж�ϵͳ���Ƿ���ڽ�����Ϣ 
	if(dealcount==0)printf("���޽�����Ϣ\n");
	
	//�˵�ѡ�� 
	printf("****************************************************************************\n");
 	printf("����ʽ��\n");
 	printf("1����Ʒ�۸�����\n");
 	printf("2����Ʒ�۸���\n");
 	printf("****************************************************************************\n");
 	
	 //��ȡ�û����� 
	int ch;
 	printf("ѡ��"); 
  	scanf("%d",&ch);
	switch (ch)
  	{
  		//���۸����� 
  		case 1: 
  		    for(int i=0;i<dealcount;i++)
		  	{
		  		for(int j=0;j<dealcount-i-1;j++)
		  		{
		  			//�Ƚ���Ʒ�۸�߶� 
		  			if(tran[j].com.price>tran[j+1].com.price)
		  			{
					  	struct transaction t;//��ʱ�洢��Ϣ 
						t=tran[j];
						tran[j]=tran[j+1];
						tran[j+1]=t;
					}
		  		}
		  	}
		  	dprint(count,goodcount,dealcount);
  			break;
  			
  		//���۸���	
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
  			printf("�����������������\n");
  			system("pause");
  			break;
  	}
  	
	system("pause");
	system("cls");
	
	writedFile(dealcount);//д���ļ� 
	
	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//�޸���Ϣ��һ�� 
void dealmodify_one(int count,int goodcount,int dealcount)
{
	int flag=0;//��¼�ý�����Ϣ�Ƿ���� flag=1������ڲ��޸� flag=0��������
	
	//�˵�ѡ�� 
	printf("****************************************************************************\n");
 	printf("���ҷ�ʽ��\n");
 	printf("1���\n");
 	printf("2��Ʒ\n");
 	printf("****************************************************************************\n");	
	
	//��ȡ�û����� 
	int ch;
 	scanf("%d",&ch);
	switch (ch)
 	{
 		//�������Ϣ��ѯ���޸� 
 		case 1: 
	 		system("cls");
			
			printf("������������ƣ�");
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
 		
		//����Ʒ��Ϣ��ѯ���޸�
		case 2: 
			system("cls");
	
	 		printf("��������Ʒ���ƣ�");
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
 			flag=2;//����������� 
 			printf("�����������������\n");
 			system("pause");
 			break;
 			
 	}
 	
	if(flag==0) printf("������ؽ��׼�¼\n");
	if(flag==1) printf("�޸ĳɹ�\n");
  	
	system("pause"); 
  	system("cls");
  	
	writedFile(dealcount);//д���ļ� 
  	
	dm(count,goodcount,dealcount);//���ؽ��ײ˵� 
}

//�޸���Ϣ������ 
void dealmodify_two(int i,int count,int goodcount)
{
	int flag=0;//�ж�����Ƿ������ϵͳ 
	
	//�˵�ѡ�� 
	printf("****************************************************************************\n");
 	printf("������Ҫ���еĲ�����\n");
 	printf("1�޸����\n");
 	printf("2�޸���Ʒ\n");
 	printf("****************************************************************************\n");
 	
 	//��ȡ���� 
	int ch;	
 	scanf("%d",&ch);
	switch (ch)
 	{
 		//�޸���� 
 		case 1:
 			printf("�޸�Ϊ��");
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
		 	if(flag==0)printf("����Ҳ�����\n"); 
 			break;
 			
		//�޸���Ʒ 	
	 	case 2:
 			printf("�޸�Ϊ��"); 
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
 		 	if(flag==0)printf("����Ʒ������\n");
 			break;
 			
 		default:
 			printf("�����������������\n");
 			system("pause");
 			break;
 	}
}
 
//�����ļ����� 
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

//�����ļ���ȡ 
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
 
//������Ŀ¼ 
void dm(int count,int goodcount,int dealcount)
 {
    printf("****************************************************************************\n");
 	printf("������Ϣ\n");
 	printf("������Ҫ���еĲ�����\n");
 	printf("1����\n");
 	printf("2����\n");
 	printf("3ɾ��\n");
 	printf("4����\n");
 	printf("5�޸�\n");
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
	 		  	menu(count,goodcount,dealcount);//�������˵� 
	 		  	break;
	 		  	
	  		default:
	  			printf("�����������������\n");
	  			flag=1; 
	  			break;
	  	}	
  	}
 }
