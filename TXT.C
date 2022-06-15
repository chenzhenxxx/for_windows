void purchase()
{   char bh[20];
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
        if(select==-1)
        {
            break;
        }
        scanf("%s",bh);
        int flag=0;
        struct medicine * p=head_p;
         while(p->next!=NULL)
        {
            struct medicine *q=p->next;
            if(strcmp(q->num,bh)==0)
             {   flag=1;
                 printf("查询成功！\n");
                 printf("%-8s\t %-8s\t %-8.2f\t\n",q->num,q->name,q->price);
                 break;
             }
             
             p=q;
        }
        if(flag==0)
        {
            printf("没有此药品！请重新输入！\n");

        }
        else
        {   if(select==1)
            {
            printf("请确认是否购买？y/n\n");
            char c;
            c=getchar();
            if(c=='y')
            {
               struct medicine *q =(struct medicine *)malloc(sizeof(struct medicine));
               strcpy(q->num,p->num);
               strcpy(q->name,p->name);
               q->price=p->price;
               head_p->next=q;
               head_p=q;

            }
            }
            else if(select==-1)
            {
                 printf("请确认是否删除？y/n\n");
                 char c;
                 c=getchar();
                 struct medicine *tmp;
             if(c=='y')
             {
              struct medicine *q=head_p->next;
              if(strcmp(q->num,bh)==0)
               {   tmp=q;
                   q=q->next;
                   head_p=head_p->next;
                  free(tmp);
           
                }
              else
              {   
                while(q->next&&q)
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
              }  

             }
            }


        }
    }

      printf("购买如下::\n");
      struct medicine * p=head_p->next;
      double all_price=0;
	   while(p&&p->next)
        {
        all_price+=p->price;
        printf("%-8s\t %-8s\t %-8.2f\t\n",p->num,p->name,p->price);
        p=p->next;
        }
        printf("请确认是否购买！y/n\n");
        char c;
        c=getchar();
        if(c=='y')
        {
            printf("%.2f元！感谢您的惠顾！\n",all_price);

        }

}