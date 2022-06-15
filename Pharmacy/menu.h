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
  
    destory_user();

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
       // case 3: purchase();break;
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
    printf(" 5.管理用戶\n");
    printf(" 6.查看收益\n");
    printf(" 7.发布公告\n");
    printf(" 8.修改密码\n");
    printf(" 9.退出\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: add();break;
        case 2: dlete_medicine();break;
        case 3: modify();break;
        case 4:insert_medicine();break;
        case 5:dlete_user();break;
       // case 6:check_income();break;
       // case 7: notice();break;
       case 8: mod_pwd();break;
       case 9: Welcome();break;
        default: printf("请输入正确的操作\n");menu_manager();break;
        
    }
    menu_manager();
}