#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct user *head_c; //�û��͹��������������ͷ 
int id=0; //�ж����û����ǹ����� 
int notice_cnt=0; //�ж�����notice 
int message_cnt=0; //�ж�����message 
char tmp_zh[100];
char now_user[100],now_manager[100];
char sudo[20]="boss"; //�������� 
struct medicine *head; //ҩƷ������ͷ 
struct medicine   //ҩ�ṹ�� 
{
    char num[10];
    char name[100];
    double price;
    int cnt;
    double total;
    struct medicine * next;
} med;
struct user //�˽ṹ�� 
{
    struct user*next;
    char  zh[30];
    char mm[30];
    
};
void init_medicine();
void show_notice();
void show_all();
int password(char *zh);
void check_good();
void message();
void purchase();
void show_message();
void add();
void dlete_medicine();
void dlete_user();
void modify();
void check_income();
void notice();
void menu_consumer();
void menu_manager();
void mod_pwd();
void get_pwd(char *buf);
void login_user();
void init_user();
void sign_up_user();
void destory_user();
void destory_medicine();
void insert_medicine();
void logout();
void down_BubbleSort(struct medicine * L);
void up_BubbleSort(struct medicine * L);
void dlete_manager();
void add_manager();
void logout();
void Welcome()  //��ӭ�˵� 
{   

   fflush(stdin);
    id=0;
    printf("*   *   *  * * *    * *    *         *        *  *      * * *\n ");
    printf("* * * *   * *    *    *   *      *     *    *  *  *    * *  \n" );
    printf("  *   *    * * *    * *    * * *     *      *       *   * * * \n");
    printf("��ӭ��������ҩ�꣡\n");
    printf("��ѡ��������\n");
    printf("1.������         2.������\n");
    scanf("%d",&id);
    if(id!=1&&id!=2)
    {
    	printf("�������\n");
    	Welcome();
	}
    getchar();
    destory_medicine(); 
    destory_user;
    init_user();
    init_medicine();
    login_user();  //��¼����

    if(id==1)
    {   
        menu_consumer();
    }
    else if(id==2)
    {  
        menu_manager();
    }
    
    else
    {    
         printf("��������ȷ�Ĳ���\n");
        
    }
     Welcome();


}
void menu_consumer() //�û��˵� 
{   int flag=0;
    if(notice_cnt!=0)
	show_notice();
    printf("��������� %s����ѡ����ķ���\n",now_user);
    printf(" 1.��ѯ����ҩƷ\n");
    printf(" 2.���̼�����\n");
    printf(" 3.����ҩƷ\n");
    printf(" 4.չʾ��������ҩƷ�嵥\n");
    printf(" 5.�޸�����\n");
    printf(" 6.ע���˻�\n");
    printf(" 7.�˳�\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: check_good();break;
        case 2: message();break;
        case 3: purchase();break;
        case 4: show_all();break; 
        case 5: mod_pwd();break;
        case 6: logout();break;
        case 7: Welcome();break; 
        default: printf("��������ȷ�Ĳ���\n");menu_consumer();break;
        
    }
    if(flag==6)
    {
    	Welcome();
	}
    menu_consumer();

}
int password(char *zh)  //��¼������֤ 
{   
	
	char buf[18];
    char tm_zh[20],pwd[20];
	FILE*fp;
    if(id==1)
    fp=fopen("consumer.txt","r");
    else if(id==2)
    fp=fopen("manager.txt","r");
	 while(!feof(fp))
    {
        fscanf(fp,"%s %s",tm_zh,pwd);
        if(strcmp(zh,tm_zh)==0)
        {   
            break;
        }
    }
	fclose(fp); 
	int len=0;
	int cnt=3;
	memset(buf,0,sizeof(buf));
	while(cnt!=0)
	{
		char c=_getch();
		if(c=='\r')
		{  
            cnt--;
			if(strcmp(pwd,buf)==0)
			{   memset(buf,0,sizeof(buf));
				return 1;
			}
			else
			{   len=0;
                printf("buf=%s\n",buf);
				printf("�㻹��%d�λ���\n",cnt);
				memset(buf,0,sizeof(buf));
			}
			
		}
		else if(c=='\b')
		 {
		 	printf("\b \b");
		 	if(len>0)
		 	{    len--;
                 buf[len]='\0';
		 	 
            }
		  } 
		  else
		  {
		  	buf[len++]=c;
		  	printf("*");
		  }
	}
	return 0;
}
void menu_manager()  //�����߲˵� 
{
     int flag=0;
     
    printf("��������� %s����ѡ����ķ���\n",now_manager);
    if(message_cnt!=0)
    {
    	printf("�����������ԣ���ע�����!\n");
	}
    printf(" 1.����ҩƷ\n");
    printf(" 2.�¼�ҩƷ\n");
    printf(" 3.�޸�ҩƷ\n");
    printf(" 4.����ҩƷ\n"); 
    printf(" 5.�鿴����\n");
    printf(" 6.��������\n");
    printf(" 7.�޸�����\n");
    printf(" 8.�����û��˻�\n"); 
    printf(" 9. �鿴���ԣ�\n");
    printf(" 10.ɾ�������ߣ�\n");
    printf(" 11.�˳�\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: add();break;
        case 2: dlete_medicine();break;
        case 3: modify();break;
        case 4:insert_medicine();break;
        case 5:check_income();break;
        case 6: notice();break;
       case 7: mod_pwd();break;
       case 8:dlete_user();break;
       case 9: show_message();break; 
       case 10: dlete_manager();break;
       case 11: Welcome();break;
        default: printf("��������ȷ�Ĳ���\n");menu_manager();break;
        
    }
    menu_manager();
}
int main() 
{   //system("color A5");
    
    Welcome();
}
void init_medicine() //��ʼ��ҩƷ������ 
{   FILE *fp;
head=(struct medicine *)malloc(sizeof(struct medicine));
head->next=NULL;
struct medicine *q;
  q=head;
    q->next=NULL;
    fp=fopen("medicine.txt","r");
    if(fp==NULL)
    {
    printf("���ܴ򿪴��ļ���");
    //quit();
    }
    while(!feof(fp))
    {   struct medicine *p=(struct medicine *)malloc(sizeof(struct medicine));
        fscanf(fp,"%s %s %lf",p->num,p->name,&p->price);
        q->next=p;
        q=p;
    }
    q->next=NULL;
    fclose(fp);
}
void destory_medicine()  //�ݻ�ҩƷ���� 
{
    struct medicine *p=head;
    while(p)
    {
        struct medicine *q=p->next;
        free(p);
        p=q;
    }

}
void add()  //���ҩƷ   
{   
    printf("���������0 �˳�add\n");
    char bh[10];
    char mz[10];
    double jg;
    struct medicine *p=head->next;
    while(p&&p->next)
    {   
        p=p->next;
    }
    FILE* fp,*fq;
    fp=fopen("medicine.txt","a+");
    fq=fopen("income.txt","a+");
    while(scanf("%s",bh)==1&&strcmp(bh,"0")!=0)
     {   int flag=0; 
	    struct medicine *r=head->next;
        while(r)
        {
            if(strcmp(r->num,bh)==0)
            {  flag=1;
               char clear[20];
               double cl;
               scanf("%s %lf",clear,&cl);
                printf("�Ѿ��д�ҩƷ��\n");
                break;
            }
            r=r->next;
        }
        if(flag==1)
        continue;
        struct medicine * q=(struct medicine *)malloc(sizeof(struct medicine));
        q->next=NULL;
        strcpy(q->num,bh);
        scanf("%s %lf",q->name,&q->price);
        p->next=q;
        p=q;
        fprintf(fp,"%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
        fprintf(fq,"%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",p->num,p->name,p->price,p->cnt,p->total);
            
   }
    p->next=NULL;
    fclose(fp);
    fclose(fq);
}
void  check_good() //��ѯҩƷ 
{   
    int select,flag=0;
    printf("    �װ��������ߣ���ѡ����ҷ�ʽ��\n");
    printf("*****ѡ��1 ��Ų��� ******\n");
    printf("*****ѡ��2 ���Ʋ��� ******\n");
    printf("*****ѡ��3 ��ż����Ʋ��� ******\n");
    printf("    *****ѡ��4 �˳� ******\n");
    scanf("%d",&select);
    if(select==1)
    {   char tmp[15];
        printf("�������ѯ���\n");
        scanf("%s",tmp);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,tmp)==0)
             {   flag=1;
                 printf("��ѯ�ɹ���\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
             
             p=q;
        }
          
                if(flag==0)
             	printf("��ѯʧ�ܣ�\n"); 
			 
        
    }
    
    else if(select==2)
    {   char tmp[15];
        printf("�������ѯҩƷ����\n");
        scanf("%s",tmp);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->name,tmp)==0)
             {   flag=1;
                 printf("��ѯ�ɹ���\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
              
             p=q;
        }
        
          
                if(flag==0)
             	printf("��ѯʧ�ܣ�\n"); 
			 
 
    }

    else if(select==3)
    {   char tmp_num[15],tmp_name[15];
        printf("�������ѯ��ź�����\n");
        scanf("%s %s",tmp_num,tmp_name);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,tmp_num)==0&&strcmp(q->name,tmp_name)==0)
             {   flag=1;
                 printf("��ѯ�ɹ���\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
             
             p=q;
        }
         
                 if(flag==0)
             	printf("��ѯʧ�ܣ�\n"); 
			 
        

    }
    
    else if(select==4)
    {
       menu_consumer();
    }

    check_good();
    
 
    
}
void show_all()  //��ʾҩ��ҩƷ�嵥 
{
	struct medicine * p=head->next;
	printf("���            ����             ����\n");
    while(p->next&&p)
    {
        
        printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
        p=p->next;
    }
}
void modify()  //�޸�ҩƷ 
{  
   char tmp[20];
   int flag=0;
   int select=0;
   printf("������Ҫ�޸ĵ�ҩƷ���(����0�˳�)\n");
   scanf("%s",&tmp);
   if(strcmp(tmp,"0")==0)
    {
        return;
    }
    struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,tmp)==0)
             {   flag=1;
                 
                  p=q;
                 break;
             }
             
             p=q;
        }

         if(flag==0)
        {
            printf("û�д˱�ţ�\n");
            modify();
        }
        else
    {
    printf("������Ҫ�޸ĵ����ͣ�\n");
    printf(" 1.���\n");
    printf(" 2.����\n");
    printf(" 3.�۸�\n");
    scanf("%d",&select);
    FILE*fp;
    fp=fopen("medicine.txt","w+");
    switch(select)
    {
        case 1: 
        {
            char s[20];
            scanf("%s",s);
            strcpy(p->num,s);
            break;
        }
         case 2: 
        {
            char s[20];
            scanf("%s",s);
            strcpy(p->name,s);
            break;
        }
        case 3: 
        {
            double s;
            scanf("%lf",&s);
            p->price=s;
            break;
        }
    }
     p=head->next;
    
     while(p&&p->next)
     {
        
         fprintf(fp,"%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
        p=p->next;

     }
    fclose(fp);
    }
    

       


}
void get_pwd(char *buf) //�������� 
{  memset(buf,0,sizeof(buf));
   int len=0;
   while(1)
	 {
		char c=_getch();
		if(c=='\r')
		{
			break;
		}
		else if(c=='\b')
		 {
		 	printf("\b \b");
             if(len>0)
		 	{    len--;
                 buf[len]='\0';
		 	 
            }
             
		  } 
		  else
		  {
		  	buf[len++]=c;
		  	printf("*");
		  }
}
}
void mod_pwd()  //�޸����� 
{  
   char tmppwd[20],tmpzh[20];
   printf("������ԭ�˺ţ�\n");
   scanf("%s",&tmpzh);
   printf("������ԭ���룡\n");
   if(!password(tmpzh))
   {
      printf("���棡������\n");
     	 Welcome();
	
   }
   else
   {
          char new1[20],new2[20];
           printf("������������\n");
           get_pwd(new1);
           printf("��ȷ��������\n");
           get_pwd(new2);
           if(strcmp(new1,new2)!=0)
           { 
             printf("�����������벻һ�£� ���������룡\n");
             mod_pwd();

           }
           else 
           {	struct user * p=head_c;
                while(p)
                {
                    if(strcmp(p->zh,tmpzh)==0)
                    {
                        strcpy(p->mm,new1);
                        break;
                    }
                    p=p->next;
                }
                FILE* fp;
                if(id==1)
                {
                    fp=fopen("consumer.txt","w");
                }
                else if(id==2)
                {
                    fp=fopen("manager.txt","w");
                }
               p=head_c->next;
          while(p)
          {  
              fprintf(fp,"%s %s\n",p->zh,p->mm);
              p=p->next;
          }
        
                printf("�޸�����ɹ���\n");
                fclose(fp);
		   }
          
       

   }
}

void init_user() //��ʼ���û� 
{  
    FILE*fp;
    head_c=(struct user *)malloc(sizeof(struct user));
head_c->next=NULL;
struct user *q;
  q=head_c;
    q->next=NULL;
    if(id==1)
    fp=fopen("consumer.txt","r");
    else if(id==2)
    fp=fopen("manager.txt","r");
    if(fp==NULL)
    {
    printf("���ܴ򿪴��ļ���");
    //quit();
    }
    while(!feof(fp))
    {   struct user *p=(struct user *)malloc(sizeof(struct user));
        fscanf(fp,"%s %s",p->zh,p->mm);
        q->next=p;
        q=p;
    }
    q->next=NULL;
    fclose(fp);
}

void sign_up_user()  //�û�ע�� 
{
    printf("�������û���\n");
    char zh[20];
    scanf("%s",zh);
     char new1[20],new2[20];
     memset(new1,0,sizeof(new1));
     memset(new2,0,sizeof(new2));
           printf("����������\n");
           get_pwd(new1);
           fflush(stdin);
           printf("\n");
           printf("��ȷ��������\n");
           get_pwd(new2);
           fflush(stdin);
           if(strcmp(new1,new2)!=0)
           {   
		   printf("�������\n");
               Welcome();
           }
           else
       {    struct user * p=head_c;
    while(p->next!=NULL)
    {
        p=p->next;
    }
     struct user *q=(struct user *)malloc(sizeof(struct user));
     q->mm[strlen(q->mm)]='\0';
     q->mm[strlen(q->zh)]='\0';
     strcpy(q->mm,new1);
      strcpy(q->zh,zh);
      p->next=q;
      p=q;

    FILE* fp;
    if(id==1)
    fp=fopen("consumer.txt","a+");
    else if(id==2)
    fp=fopen("manager.txt","a+");
    fprintf(fp,"%-8s\t %-8s\t\n",q->zh,q->mm);
    
    p->next=NULL;
    fclose(fp);
       }


     
}

void login_user()  //�û���¼ 
{   
    int flag=0;
    printf("�������˺�:\n");
    char zh[20];
    char tm_zh[20],tm_pwd[20];
    scanf("%s",&zh);
    strcpy(tmp_zh,zh);
    FILE*fp;
    if(id==1)
    {   strcpy(now_user,zh);
        fp=fopen("consumer.txt","r");
    }
    else if(id==2)
    {   strcpy(now_manager,zh);
        fp=fopen("manager.txt","r");
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",tm_zh,tm_pwd);
        if(strcmp(zh,tm_zh)==0)
        {   
            flag=1;
        }
    }
    if(flag==0&&id==1)
    { printf("�װ����û���������δ���˻����Ƿ�ע�᣿ y/n\n");
      getchar();
      char c;
      scanf("%c",&c);
      if(c=='n')
      {
          Welcome();
      }
      else
      { 
        sign_up_user();
      }
      
    }
    else if(flag==0&&id==2)
    {   printf("�װ��Ĺ�������������δ���˻����Ƿ�ע�᣿ y/n\n");
         getchar();
        char c;
        scanf("%c",&c);
         if(c=='n')
         {
          Welcome();
         }
      else
      { 
        add_manager();
      }
	}
    else
    { printf("����������\n");
      if(!password(zh))
      {
          printf("��¼ʧ�ܣ�\n");
          Welcome();
      }
      else 
      {
          printf("Welcome �û� :%s\n",zh);
      }
    }

}

void insert_medicine() //����ҩƷ 
{  
   int flag=0;
   struct medicine *p=head;
   char num[20];
   char tmp_num[20],tmp_name[20];
   double tmp_price;
   printf("��������������!(����-1�˳�)\n");
    scanf("%s",tmp_num);
    if(strcmp(tmp_num,"-1")==0)
     {
         return;
     }
   scanf("%s %lf",tmp_name,&tmp_price);
   printf("�����������Ķ����ţ�(���� 0���뵽ͷ��)\n");
   scanf("%s",num);
   while(p&&p->next)
   {
       if(strcmp(p->num,num)==0)
       {
           flag=1;
           break;
       }
       p=p->next;
   }
   if(flag==0&&strcmp(num,"0")!=0)
   {
       printf("û�д˶���\n");
       return;
      
   }
   else 
   {
     struct medicine *q=(struct medicine *)malloc(sizeof(struct medicine));
     q->next=NULL;
     strcpy(q->num,tmp_num);
      strcpy(q->name,tmp_name);
      q->price=tmp_price;
      
      if(strcmp(num,"0")==0)
       {  
          q->next=head->next;
          head->next=q;

       }
       else
      {  
      q->next=p->next;
      p->next=q;
      }
   }
      FILE* fp;
      fp=fopen("medicine.txt","w");
      p=head->next;
      while(p&&p->next)
      {   printf("1\n");
          fprintf(fp,"%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
          p=p->next;
      }
      fclose(fp);

   

}

void dlete_medicine() //ɾ��ҩƷ 
{   
    char num[20];
    char yao[20];
    int flag=0;
    printf("��������ɾ���ı��(����0�˳�)\n");
    scanf("%s",num);
    if(strcmp(num,"0")==0)
     {
         return;
     }
    struct medicine *p=head->next;
    struct medicine *tmp=NULL; 
    while(p)
    {
        if(strcmp(p->num,num)==0)
        {   strcpy(yao,p->name);
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0)
    {
        printf("û�д�ҩƷ��\n");
    }
    else
    {
        struct medicine *q=head;
      
            while(q->next)
            {
                if(strcmp(q->next->num,num)==0)
                {
                    tmp=q->next;
                    q->next=q->next->next;
                    free(tmp);
                    break;
                }
                q=q->next;
            }


     
        FILE*fp;
        fp=fopen("medicine.txt","w+");

        p=head->next;
        while(p&&p->next)
        {  fprintf(fp,"%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
            p=p->next;
        }
        fclose(fp);
        printf("ɾ��ҩƷ%s �ɹ���\n",yao);

    }
}


void dlete_user() //ɾ���û� 
{  
   char bh[20];
   int flag=0;
   struct user * head_tmp,*q,*p,*tmp;
   head_tmp=(struct user *)malloc(sizeof(struct user));
   head_tmp->next=NULL;
   q=head_tmp;
   FILE *fp;
   fp=fopen("consumer.txt","r");
   while(!feof(fp))
   { struct user*p=(struct user *)malloc(sizeof(struct user));
   	 fscanf(fp,"%s %s",p->zh,p->mm);
   	 q->next=p;
   	 q=p;
   }
   q->next=NULL;
   
   printf("������Ҫɾ���ı��\n");
   scanf("%s",bh);
   p=head_tmp;
   while(p->next)
   {
   	if(strcmp(p->next->zh,bh)==0)
   	 {
   	 	 flag=1;
   	 	 break;
	 }
	 p=p->next;
   }
    
   if(flag==0)
   {
   	printf("û�д��û���\n");
   }
   else if(flag==1)
    {     id=1;
        
		
		
		
    	p=head_tmp;
    	while(p->next)
    	{
    		if(strcmp(p->next->zh,bh)==0)
    		 {
    		 	tmp=p->next;
    		 	p->next=p->next->next;
    		 	free(tmp);
    		 	break;
			 }
			 p=p->next;
		}
		 //printf("6666\n");
		FILE*fp;
        fp=fopen("consumer.txt","w+");

        p=head_tmp->next;
        while(p&&p->next)
        {  fprintf(fp,"%-8s\t %-8s\t\n",p->zh,p->mm);
            p=p->next;
        }
        fclose(fp);
	}
	   id=2;
	   p=head_tmp->next;
       while(p)
       {
       	struct user *tmp;
       	tmp=p->next;
       	free(p);
       	p=p->next;
	   }
	   free(head_tmp);
   
   
   
   
   
}

void purchase() //����ҩƷ 
{   
    char bh[20];
    int cnt[60000];
	 memset(cnt,0,sizeof(cnt)); 
	show_all();
    struct medicine *head_p =(struct medicine *)malloc(sizeof(struct medicine));
    head_p->next=NULL;
    int select=0;
    printf("*************������Ҫ�����ҩƷ����!******************\n");
    printf("*** ����0��������***\n");
    printf("*** ����1����***\n");
    printf("*** ����-1�޸Ĺ����嵥��ĳһ�***\n");
    while(scanf("%d",&select)==1&&select!=0)

    {   
        if(select==0)
        {
            break;
        }
        printf("������Ҫ����/ɾ���ı�ţ�\n");
        scanf("%s",bh);
        int flag=0;
        struct medicine * p=head->next;
         while(p)
        {
            
            if(strcmp(p->num,bh)==0)
             {   flag=1;
                 printf("��ѯ�ɹ���\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
                 break;
             }
             
             p=p->next;
        }
        if(flag==0)
        {
            printf("û�д�ҩƷ�����������룡\n");

        }
        else
        {   if(select==1)
            {
              int count=0;
              printf("�����빺��������\n");
              scanf("%d",&count);
              
            printf("��ȷ���Ƿ���y/n\n"); 
            char c;
            getchar();
            scanf("%c",&c);
            if(c=='y')
            {  if(cnt[atoi(bh)]==0)
			   {
				
               struct medicine *q =(struct medicine *)malloc(sizeof(struct medicine));
               strcpy(q->num,p->num);
               strcpy(q->name,p->name);
               q->price=p->price;
               q->total+=count*q->price;
               struct medicine *r=head_p;
               while(r->next)
               {
               	r=r->next;
			   }
			   r->next=q;
			   q->next=NULL;
		       }
		        cnt[atoi(bh)]+=count;

            }
            }
            else if(select==-1)
            {
                 printf("��ȷ���Ƿ�ɾ����y/n\n");
                 getchar();
                 char c;
                 c=getchar();
                 struct medicine *tmp;
             if(c=='y')
             { q->total=0;
               struct medicine *q=head_p;
      
                  while(q->next)
               {
                     if(strcmp(q->next->num,bh)==0)
                  {
                       tmp=q->next;
                       q->next=q->next->next;
                       free(tmp);
                       break;
                  }
                q=q->next;
               }
               cnt[atoi(bh)]=0;
            }


           }

        }
           printf("*************������Ҫ�����ҩƷ����!******************\n");
          printf("*** ����0��������***\n");
         printf("*** ����1����***\n");
        printf("*** ����-1�޸Ĺ����嵥��ĳһ�***\n");
    }

      printf("��������::\n");
      up_BubbleSort(head_p);; //��������
      struct medicine * p=head_p->next;

      double all_price=0;
	   while(p)
        { 
        all_price+=p->price*cnt[atoi(p->num)];
        printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price*cnt[atoi(p->num)]);
        p=p->next;
        }
        printf("��ȷ���Ƿ���y/n\n");
        getchar();
        char c;
        c=getchar();
        if(c=='y')
        {   FILE* fp=fopen("income.txt","r");
            struct medicine *head_i=(struct medicine*)malloc(sizeof(struct medicine));
            head_i->next=NULL;
            struct medicine *r;
            r=head_i;
            
            while(!feof(fp))
            {  struct medicine *tmp=(struct medicine *)malloc(sizeof(struct medicine));
               fscanf(fp,"%s %s %lf %d %lf",tmp->num,tmp->name,&tmp->price,&tmp->cnt,&tmp->total);
               tmp->cnt+=cnt[atoi(tmp->num)];
               tmp->total=tmp->cnt*tmp->price;
               r->next=tmp;
               r=tmp;
            }
           
            r->next=NULL;
            fclose(fp);
            fp=fopen("income.txt","w");
            r=head_i->next;
            while(r&&r->next)
            {
                 fprintf(fp,"%-8s\t %-8s\t %.2f\t %d\t %.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
                 r=r->next;
            }
            fclose(fp);

           
            printf("%.2fԪ����л���Ļݹˣ�\n",all_price);
            r=head_i;
            while(r->next)
             {
             	struct medicine *tmp;
             	tmp=r->next;
             	free(r);
             	r=tmp;
			 }

        }

}

void check_income()  //ͳ������ 
{  
   int select=0;
   double all_price=0,part_price=0;
   printf("**********��ѡ��ͳ�����ͣ�*************\n");
   printf("***** ****1.ͳ�������棡*********\n");
   printf("**********2.ͳ���۳��������ڣ���\n");
   printf("**********3.ͳ�Ƽ۸���ڣ������ҳ�����ֵ�������ڣ�������Ʒ��***********************\n");
   scanf("%d",&select);
   FILE* fp=fopen("income.txt","r");
            struct medicine *head_i=(struct medicine*)malloc(sizeof(struct medicine));
            head_i->next=NULL;
            struct medicine *r;
            r=head_i;
            while(!feof(fp))
            {  struct medicine *tmp=(struct medicine *)malloc(sizeof(struct medicine));
               fscanf(fp,"%s %s %lf %d %lf",tmp->num,tmp->name,&tmp->price,&tmp->cnt,&tmp->total);
               all_price+=tmp->total;
               r->next=tmp;
               r=tmp;
            }
           
            r->next=NULL;
            fclose(fp);

   if(select==1)
   {
      printf("������:\n");
      printf("%.2fԪ!\n",all_price);
      up_BubbleSort(head_i);
      r=head_i->next->next; 
      printf("���            ����             ����           ����             �ܼ�  \n");
      while(r)
       {
        printf("%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
        r=r->next;
        }
   }
   else if(select==2)
   { int cnt=0;
   	printf("�������۳���������\n");
   	scanf("%d",&cnt);
     up_BubbleSort(head_i);
      r=head_i->next->next; 
       while(r)
       {
           if(r->cnt>=cnt)
           {
               part_price+=r->total;
           }
           r=r->next;
       }
      printf("����������:\n");
      printf("%.2fԪ!\n",part_price);
      r=head_i->next->next;
       printf("���            ����             ����           ����             �ܼ�  \n");
      while(r)
       {  if(r->cnt>=cnt)
        printf("%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
        r=r->next;
        }
   	
   	
	} 
   else if(select==3)
   {   double price=0,total=0;
       printf("�����뵥������!\n");
       scanf("%lf",&price);
       printf("�����������ֵ���ƣ�\n");
       scanf("%lf",&total);
        up_BubbleSort(head_i);
      r=head_i->next->next; 
       while(r)
       {
           if(r->total>=total&&r->price>=price)
           {
               part_price+=r->total;
           }
           r=r->next;
       }
      printf("����������:\n");
      printf("%.2fԪ!\n",part_price);
      r=head_i->next->next;
       printf("���            ����             ����           ����             �ܼ�  \n");
      while(r)
       { if(r->total>=total&&r->price>=price)
        printf("%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
        r=r->next;
        } 


   }
   
            r=head_i;
            while(r->next)
             {
             	struct medicine *tmp;
             	tmp=r->next;
             	free(r);
             	r=tmp;
			 }


}


void notice()
{   char s[200];
    FILE *fp=fopen("notice.txt","a+");
	printf("��������������ĸ�ʾ��(����0�˳�)\n");
	while(scanf("%s",s)==1&&strcmp(s,"0")!=0)
	{ notice_cnt++;
	  fprintf(fp,"%s\n",s);	
	} 
	fclose(fp);
	

} 
void message()
{   char s[200];
    FILE *fp=fopen("message.txt","a+");
	printf("������������������ԣ�(����0�˳�)\n");
	while(scanf("%s",s)==1&&strcmp(s,"0")!=0)
	{ message_cnt++;
	  fprintf(fp,"%s %s\n",tmp_zh,s);	
	} 
	fclose(fp);
	

} 
void show_notice()
{
	FILE*fp=fopen("notice.txt","r");
	while(!feof(fp)&&notice_cnt--)
	{   char s[100];
	    fscanf(fp,"%s",s);
		printf("notice:%s\n",s);
	}
	fclose(fp);
	fp=fopen("notice.txt","w");
	fclose(fp);
	notice_cnt=0;
 } 
 void show_message()
{
	FILE*fp=fopen("message.txt","r");
	while(!feof(fp)&&message_cnt--)
	{   char s[100],zh[100];
	    fscanf(fp," %s %s",zh,s);
		printf("message from %s :%s\n",zh,s);
	}
	fclose(fp);
	fp=fopen("message.txt","w");
	fclose(fp);
	message_cnt=0; 
 } 

 void add_manager()
 {
 	FILE* fp;
    printf("������sudo����!\n");
    char pwd[20];
	get_pwd(pwd);
	if(strcmp(pwd,sudo)!=0)
	 {
	 	printf("�������\n");
         Welcome();
	  } 
	 else
	{   char zh[20],mm[20];
		FILE*fp;
		fp=fopen("manager.txt","a");
		printf("����������ӵĹ����ߣ�\n");
		scanf("%s",zh);
		char new1[20],new2[20];
           printf("������������\n");
           get_pwd(new1);
           printf("��ȷ��������\n");
           get_pwd(new2);
           if(strcmp(new1,new2)!=0)
           { printf("%s | %s\n",new1,new2);
             printf("�����������벻һ��!\n");
             Welcome();
             
           }
           else
		   {
		   	fprintf(fp,"%s %s\n",zh,new1);
		   	printf("Welcome new manager %s!\n",zh);
			} 
			fclose(fp);
		
	}
    
 } 
 
 
 void dlete_manager() //ɾ���û� 
{  
   char bh[20];
   int flag=0;
   struct user * head_tmp,*q,*p,*tmp;
   printf("������sudo ���룡\n");
   char pwd[20];
   get_pwd(pwd);
   if(strcmp(pwd,sudo)!=0)
   { 
   	printf("sudo�������\n");
   	return;
	} 
   head_tmp=(struct user *)malloc(sizeof(struct user));
   head_tmp->next=NULL;
   q=head_tmp;
   FILE *fp;
   fp=fopen("manager.txt","r");
   while(!feof(fp))
   { struct user*p=(struct user *)malloc(sizeof(struct user));
   	 fscanf(fp,"%s %s",p->zh,p->mm);
   	 q->next=p;
   	 q=p;
   }
   q->next=NULL;
   
   printf("������Ҫɾ���ı��\n");
   scanf("%s",bh);
   p=head_tmp;
   while(p->next)
   {
   	if(strcmp(p->next->zh,bh)==0)
   	 {
   	 	 flag=1;
   	 	 break;
	 }
	 p=p->next;
   }
   
    //printf("1111111111111\n");
    
   if(flag==0)
   {
   	printf("û�й����ߣ�\n");
   }
   else if(flag==1)
    {    
        
		
		
		
    	p=head_tmp;
    	while(p->next)
    	{
    		if(strcmp(p->next->zh,bh)==0)
    		 {
    		 	tmp=p->next;
    		 	p->next=p->next->next;
    		 	free(tmp);
    		 	break;
			 }
			 p=p->next;
		}
		//printf("2222222222111111\n");
		FILE*fp;
        fp=fopen("manager.txt","w+");

        p=head_tmp->next;
        while(p)
        {  fprintf(fp,"%-8s\t %-8s\t\n",p->zh,p->mm);
            p=p->next;
        }
        fclose(fp);
        //printf("333333333111111\n");
	}
	   p=head_tmp;
       while(p->next)
       {
       	struct user *tmp;
       	tmp=p->next;
       	free(p);
       	p=tmp;
	   }
	   
       // printf("444444444\n");
   
   
   
   
}
void logout()
{   printf("����˼�� y/n\n");
    char c;
    getchar();
    c=getchar();
    if(c=='n')
    {
        return;

    }
    else 
    { printf("���������룡\n");
    if(!password(now_user))
    {
        printf("�������\n");
    }
    else
    {   
      int flag=0;
      struct user * head_tmp,*q,*p,*tmp;
      head_tmp=(struct user *)malloc(sizeof(struct user));
      head_tmp->next=NULL;
      q=head_tmp;
      FILE *fp;
      fp=fopen("consumer.txt","r");
      while(!feof(fp))
      { struct user*p=(struct user *)malloc(sizeof(struct user));
   	    fscanf(fp,"%s %s",p->zh,p->mm);
   	    q->next=p;
   	  q=p;
      }
      q->next=NULL;
      p=head_tmp;
      while(p->next)
     {
   	   if(strcmp(p->next->zh,now_user)==0)
   	   {
   	 	  flag=1;
   	 	  break;
	   }
	   p=p->next;
     }
    	p=head_tmp;
    	while(p->next)
    	{
    		if(strcmp(p->next->zh,now_user)==0)
    		 {
    		 	tmp=p->next;
    		 	p->next=p->next->next;
    		 	free(tmp);
    		 	break;
			 }
			 p=p->next;
		}
		 
        fp=fopen("consumer.txt","w+");

        p=head_tmp->next;
        while(p&&p->next)
        {  fprintf(fp,"%-8s\t %-8s\t\n",p->zh,p->mm);
            p=p->next;
        }
        fclose(fp);
	    
	   p=head_tmp->next;
       while(p)
       {
       	struct user *tmp;
       	tmp=p->next;
       	free(p);
       	p=tmp;
	   }
	   
	   free(head_tmp);
        printf("�װ���%s �û���������Ե�ټ�!\n",now_user);
    }
}
}

void up_BubbleSort(struct medicine * L)
{
	int i ,count = 0, num;//count��¼������ĸ�����num�����ڲ�ѭ����
	struct medicine  *p, *q, *tail;//��������ָ�룬����ð������
	p = L;
	while(p->next != NULL)//��������ĸ���
	{
		count++;//ע�͢�
		p = p->next;
	}
	for(i = 0; i < count - 1; i++)//���ѭ����������ð������һ��
	{
		num = count - i - 1;//��¼�ڲ�ѭ����Ҫ�Ĵ�����������ð������һ����
		q = L->next;//��qָ���һ�����
		p = q->next;//��pָ���һ�����
		tail = L;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
		while(num--)//�ڲ�ѭ�� ����������ð������һ��
		{
			if(q->total > p->total)//����ý���ֵ���ں�һ����㣬�򽻻�
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//ע�͢�
			q = tail->next;//ע�͢�
			p = q->next;//ע�͢�
		 } 
	} 
}

void down_BubbleSort(struct medicine * L)
{
	int i ,count = 0, num;//count��¼������ĸ�����num�����ڲ�ѭ����
	struct medicine  *p, *q, *tail;//��������ָ�룬����ð������
	p = L;
	while(p->next != NULL)//��������ĸ���
	{
		count++;//ע�͢�
		p = p->next;
	}
	for(i = 0; i < count - 1; i++)//���ѭ����������ð������һ��
	{
		num = count - i - 1;//��¼�ڲ�ѭ����Ҫ�Ĵ�����������ð������һ����
		q = L->next;//��qָ���һ�����
		p = q->next;//��pָ���һ�����
		tail = L;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
		while(num--)//�ڲ�ѭ�� ����������ð������һ��
		{
			if(q->total < p->total)//����ý���ֵ���ں�һ����㣬�򽻻�
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//ע�͢�
			q = tail->next;//ע�͢�
			p = q->next;//ע�͢�
		 } 
	} 
}
