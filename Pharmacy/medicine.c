
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct user *head_c;
int id=0;
int notice_cnt=0;
int message_cnt=0;
struct medicine *head;
struct medicine
{
    char num[10];
    char name[100];
    double price;
    int cnt;
    double total;
    struct medicine * next;
} med;
struct user
{
    struct user*next;
    char  zh[30];
    char mm[30];
    
};
struct user *head_c;
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
void Welcome()
{   fflush(stdin);
    id=0;
    printf("*   *   *  * * *    * *    *         *        *  *      * * *\n ");
    printf("* * * *   * *    *    *   *      *     *    *  *  *    * *  \n" );
    printf("  *   *    * * *    * *    * * *     *      *       *   * * * \n");
    printf("欢迎来到西邮药店！\n");
    printf("请选择你的身份\n");
    printf("1.消费者         2.管理者\n");
    scanf("%d",&id);
    getchar();
    destory_medicine(); 
    destory_user;
    init_user();
    init_medicine();
    login_user();  //登录界面

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
         printf("请输入正确的操作\n");
        
    }
     Welcome();


}
void menu_consumer()
{   int flag=0;
    //show_notice();
    printf("你好消费者，请选择你的服务！\n");
    printf(" 1.查询本店药品\n");
    printf(" 2.给商家留言\n");
    printf(" 3.购买药品\n");
    printf(" 4.展示本店已有药品清单\n");
    printf(" 5.修改密码\n");
    printf(" 6.注销账户\n");
    printf(" 7.退出\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: check_good();break;
       // case 2: message();break;
        case 3: purchase();break;
        case 4: show_all();break; 
        case 5: mod_pwd();break;
        case 6: dlete_user();break;
        case 7: Welcome();break; 
        default: printf("请输入正确的操作\n");menu_consumer();break;
        
    }
    menu_consumer();

}
int password(char *zh)
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
				printf("你还有%d次机会\n",cnt);
				memset(buf,0,sizeof(buf));
			}
			
		}
		else if(c=='\b')
		 {
		 	printf("\b \b");
		 	len--;
		 	buf[len]='\0';
		  } 
		  else
		  {
		  	buf[len++]=c;
		  	printf("*");
		  }
	}
	return 0;
}
void menu_manager()
{
     int flag=0;
     //show_message();
    printf("你好生产者，请选择你的服务！\n");
    printf(" 1.上新药品\n");
    printf(" 2.下架药品\n");
    printf(" 3.修改药品\n");
    printf(" 4.插入药品\n"); 
    printf(" 5.查看收益\n");
    printf(" 6.发布公告\n");
    printf(" 7.修改密码\n");
    printf(" 8.管理账户\n"); 
    printf(" 9.退出\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: add();break;
        case 2: dlete_medicine();break;
        case 3: modify();break;
        case 4:insert_medicine();break;
        case 5:check_income();break;
       // case 6: notice();break;
       case 7: mod_pwd();break;
       case 8:dlete_user();break;
       case 9: Welcome();break;
        default: printf("请输入正确的操作\n");menu_manager();break;
        
    }
    menu_manager();
}
int main()
{   //system("color A5");
    
    Welcome();
}
void init_medicine()
{   FILE *fp;
head=(struct medicine *)malloc(sizeof(struct medicine));
head->next=NULL;
struct medicine *q;
  q=head;
    q->next=NULL;
    fp=fopen("medicine.txt","r");
    if(fp==NULL)
    {
    printf("不能打开此文件！");
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
void destory_medicine()
{
    struct medicine *p=head;
    while(p)
    {
        struct medicine *q=p->next;
        free(p);
        p=q;
    }

}
void add()
{   printf("当编号输入0 退出add\n");
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
    {   struct medicine * q=(struct medicine *)malloc(sizeof(struct medicine));
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
void  check_good()
{   int select,flag=0;
    printf("    亲爱的消费者，请选择查找方式！\n");
    printf("*****选项1 编号查找 ******\n");
    printf("*****选项2 名称查找 ******\n");
    printf("*****选项3 编号加名称查找 ******\n");
    printf("    *****选项4 退出 ******\n");
    scanf("%d",&select);
    if(select==1)
    {   char tmp[15];
        printf("请输入查询编号\n");
        scanf("%s",tmp);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,tmp)==0)
             {   flag=1;
                 printf("查询成功！\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
             
             p=q;
        }
          
                if(flag==0)
             	printf("查询失败！\n"); 
			 
        
    }
    
    else if(select==2)
    {   char tmp[15];
        printf("请输入查询药品名称\n");
        scanf("%s",tmp);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->name,tmp)==0)
             {   flag=1;
                 printf("查询成功！\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
              
             p=q;
        }
        
          
                if(flag==0)
             	printf("查询失败！\n"); 
			 
 
    }

    else if(select==3)
    {   char tmp_num[15],tmp_name[15];
        printf("请输入查询编号和名称\n");
        scanf("%s %s",tmp_num,tmp_name);
        struct medicine *p=head;
        while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,tmp_num)==0&&strcmp(q->name,tmp_name)==0)
             {   flag=1;
                 printf("查询成功！\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
             
             p=q;
        }
         
                 if(flag==0)
             	printf("查询失败！\n"); 
			 
        

    }
    
    else if(select==4)
    {
       menu_consumer();
    }

    check_good();
    
 
    
}
void show_all()
{
	struct medicine * p=head->next;
	printf("编号            名称             单价\n");
    while(p->next&&p)
    {
        
        printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
        p=p->next;
    }
}
void modify()
{  char tmp[20];
   int flag=0;
   int select=0;
   printf("请输入要修改的药品编号\n");
   scanf("%s",&tmp);
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
            printf("没有此编号！\n");
            modify();
        }
        else
    {
    printf("请输入要修改的类型！\n");
    printf(" 1.编号\n");
    printf(" 2.名称\n");
    printf(" 3.价格\n");
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
void get_pwd(char *buf)
{    int len=0;
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
		 	len--;
		  } 
		  else
		  {
		  	buf[len++]=c;
		  	printf("*");
		  }
}
}
void mod_pwd()
{  char tmppwd[20],tmpzh[20];
   printf("请输入原账号！\n");
   scanf("%s",&tmpzh);
   printf("请输入原密码！\n");
   if(!password(tmpzh))
   {
      printf("警告！！！！\n");
     	 Welcome();
	
   }
   else
   {
          char new1[20],new2[20];
           printf("请输入新密码\n");
           get_pwd(new1);
           printf("请确认新密码\n");
           get_pwd(new2);
           if(strcmp(new1,new2)!=0)
           { 
             printf("两次输入密码不一致！ 请重新输入！\n");
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
        
                printf("修改密码成功！\n");
                fclose(fp);
		   }
          
       

   }
}

void init_user()
{  FILE*fp;
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
    printf("不能打开此文件！");
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

void sign_up_user()
{
    printf("请输入用户名\n");
    char zh[20];
    scanf("%s",zh);
     char new1[20],new2[20];
     memset(new1,0,sizeof(new1));
     memset(new2,0,sizeof(new2));
           printf("请输入密码\n");
           get_pwd(new1);
           fflush(stdin);
           printf("\n");
           printf("请确认新密码\n");
           get_pwd(new2);
           fflush(stdin);
           if(strcmp(new1,new2)!=0)
           {   printf("%s|%s",new1,new2);
		   printf("密码错误！\n");
               login_user();
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

void login_user()
{   int flag=0;
    printf("请输入账号:\n");
    char zh[20];
    char tm_zh[20],tm_pwd[20];
    scanf("%s",&zh);
    FILE*fp;
    if(id==1)
    fp=fopen("consumer.txt","r");
    else if(id==2)
    fp=fopen("manager.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",tm_zh,tm_pwd);
        if(strcmp(zh,tm_zh)==0)
        {   
            flag=1;
        }
    }
    if(flag==0&&id==1)
    { printf("亲爱的用户现在您尚未有账户，是否注册？ y/n\n");
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
    else
    { printf("请输入密码\n");
      if(!password(zh))
      {
          printf("登录失败！\n");
          Welcome();
      }
      else 
      {
          printf("Welcome 用户 :%s\n",zh);
      }
    }

}

void insert_medicine()
{  int flag=0;
   struct medicine *p=head;
   char num[20];
   char tmp_num[20],tmp_name[20];
   double tmp_price;
   printf("请输入插入的数据! \n");
   scanf("%s %s %lf",tmp_num,tmp_name,&tmp_price);
   printf("请输入想插入的对象编号！\n");
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
   if(flag==0)
   {
       printf("没有此对象！\n");
      
   }
   else if(flag==1)
   {
     struct medicine *q=(struct medicine *)malloc(sizeof(struct medicine));
     q->next=NULL;
     strcpy(q->num,tmp_num);
      strcpy(q->name,tmp_name);
      q->price=tmp_price;
      q->next=p->next;
      p->next=q;
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

}

void dlete_medicine()
{   char num[20];
    int flag=0;
    printf("请输入想删除的编号\n");
    scanf("%s",num);
    struct medicine *p=head->next;
    struct medicine *tmp=NULL; 
    while(p)
    {
        if(strcmp(p->num,num)==0)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0)
    {
        printf("没有此药品！\n");
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

    }
}


void dlete_user()
{  char bh[20];
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
   
   printf("请输入要删除的编号\n");
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
   	printf("没有此用户！\n");
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
		 printf("6666\n");
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

void purchase()
{   char bh[20];
    int cnt[60000];
	 memset(cnt,0,sizeof(cnt)); 
	show_all();
    struct medicine *head_p =(struct medicine *)malloc(sizeof(struct medicine));
    head_p->next=NULL;
    int select=0;
    printf("*************请输入要购买的药品名称!******************\n");
    printf("*** 输入0结束购买！***\n");
    printf("*** 输入1购买！***\n");
    printf("*** 输入-1修改购买清单的某一项！***\n");
    while(scanf("%d",&select)==1&&select!=0)

    {   
        if(select==0)
        {
            break;
        }
        printf("请输入要购买/删除的编号！\n");
        scanf("%s",bh);
        int flag=0;
        struct medicine * p=head->next;
         while(p)
        {
            
            if(strcmp(p->num,bh)==0)
             {   flag=1;
                 printf("查询成功！\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
                 break;
             }
             
             p=p->next;
        }
        if(flag==0)
        {
            printf("没有此药品！请重新输入！\n");

        }
        else
        {   if(select==1)
            {
              int count=0;
              printf("请输入购买数量！\n");
              scanf("%d",&count);
              
            printf("请确认是否购买？y/n\n"); 
            char c;
            getchar();
            scanf("%c",&c);
            printf("this %c\n",c);
            if(c=='y')
            {  if(cnt[atoi(bh)]==0)
			   {
				
               struct medicine *q =(struct medicine *)malloc(sizeof(struct medicine));
               strcpy(q->num,p->num);
               strcpy(q->name,p->name);
               q->price=p->price;
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
                 printf("请确认是否删除？y/n\n");
                 getchar();
                 char c;
                 c=getchar();
                 struct medicine *tmp;
             if(c=='y')
             {
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
           printf("*************请输入要购买的药品名称!******************\n");
          printf("*** 输入0结束购买！***\n");
         printf("*** 输入1购买！***\n");
        printf("*** 输入-1修改购买清单的某一项！***\n");
    }

      printf("购买如下::\n");
      struct medicine * p=head_p->next;
      double all_price=0;
	   while(p)
        { 
        all_price+=p->price*cnt[atoi(p->num)];
        printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price*cnt[atoi(p->num)]);
        p=p->next;
        }
        printf("请确认是否购买！y/n\n");
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

           
            printf("%.2f元！感谢您的惠顾！\n",all_price);
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

void check_income()
{  int select=0;
   double all_price=0,part_price=0;
   printf("**********请选择统计类型！*************\n");
   printf("***** ****1.统计总收益！*********\n");
   printf("**********2.统计售出数量大于（）\n");
   printf("**********3.统计价格大于（）并且出售总值（）大于（）的商品！***********************\n");
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
      printf("总收入:\n");
      printf("%.2f元!\n",all_price);
      r=head_i->next; 
      printf("编号            名称             单价           数量             总价  \n");
      while(r&&r->next)
       {
        printf("%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
        r=r->next;
        }
   }
   else if(select==2)
   { int cnt=0;
   	printf("请输入售出总数限制\n");
   	scanf("%d",&cnt);
   	r=head_i->next;
       while(r)
       {
           if(r->cnt>=cnt)
           {
               part_price+=r->total;
           }
           r=r->next;
       }
      printf("部分总收入:\n");
      printf("%.2f元!\n",part_price);
      r=head_i->next;
       printf("编号            名称             单价           数量             总价  \n");
      while(r&&r->next)
       {  if(r->cnt>=cnt)
        printf("%-8s\t %-8s\t %-8.2f\t %-8d\t %-8.2f\t\n",r->num,r->name,r->price,r->cnt,r->total);
        r=r->next;
        }
   	
   	
	} 
   else if(select==3)
   {   double price=0,total=0;
       printf("请输入单价限制!\n");
       scanf("%lf",&price);
       printf("请输入出售总值限制！\n");
       scanf("%lf",&total);
       r=head_i->next;
       while(r)
       {
           if(r->total>=total&&r->price>=price)
           {
               part_price+=r->total;
           }
           r=r->next;
       }
      printf("部分总收入:\n");
      printf("%.2f元!\n",part_price);
      r=head_i->next;
       printf("编号            名称             单价           数量             总价  \n");
      while(r&&r->next)
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
