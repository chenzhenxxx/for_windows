#include"medicine.h"
#include<stdio.h>
int id=0;
int notice_cnt=0;
int message_cnt=0;
struct medicine *head;
struct medicine
{
    char num[10];
    char name[100];
    double price;
    struct medicine * next;
} med;
void init();
void show_notice();
void check_good();
void message();
void purchase();
void show_message();
void add();
void dlete();
void modify();
void check_income();
void notice();
void menu_consumer();
void menu_manger();
void Welcome()
{   
    printf("*   *   *  * * *    * *    *         *        *  *      * * *\n ");
    printf("* * * *   * *    *    *   *      *     *    *  *  *    * *  \n" );
    printf("  *   *    * * *    * *    * * *     *      *       *   * * * \n");
    printf("��ӭ��������ҩ�꣡\n");
    printf("��ѡ��������\n");
    printf("1.������         2.������");
    scanf("%d",&id);
    if(id==1)
    {
        menu_consumer();
    }
    if(id==2)
    {
        menu_manger();
    }
    else
    {
         printf("��������ȷ�Ĳ���\n");
         Welcome();
    }


}
void menu_consumer()
{   int flag=0;
    show_notice();
    printf("��������ߣ���ѡ����ķ���\n");
    printf(" 1.��ѯ����ҩƷ\n");
    printf(" 2.���̼�����\n");
    printf(" 3.����ҩƷ\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: check_good();break;
        case 2: message();break;
        case 3: purchase();break;
        default: printf("��������ȷ�Ĳ���\n");menu_consumer();break;
        
    }

}
void menu_manager()
{
     int flag=0;
     show_message();
    printf("��������ߣ���ѡ����ķ���\n");
    printf(" 1.����ҩƷ\n");
    printf(" 2.�¼�ҩƷ\n");
    printf(" 3.�޸�ҩƷ\n");
    printf(" 4.�鿴����\n");
    printf(" 5.��������\n");
    scanf("%d",&flag);
    switch(flag)
    {
        case 1: add();break;
        case 2: dlete();break;
        case 3: modify();break;
        case 4:check_income();break;
        case 5: notice();break;
        default: printf("��������ȷ�Ĳ���\n");menu_manager();break;
        
    }
}
int main()
{   //system("color A5");
    
    init(head);
    Welcome();
}
void init()
{   FILE *fp;
struct medicine *q;
  q=head;
    q->next=NULL;
    fp=fopen("medicine.txt","r");
    if(fp==NULL)
    {
    printf("���ܴ򿪴��ļ���");
    quit();
    }
    while(!feof(fp))
    {   struct medicine *p=(struct medicine *)malloc(sizeof(struct medicine));
        fscanf(fp,"%s %s %lf",&p->num,&p->name,&p->price);
        q->next=p;
        q=p;
    }
    q->next=NULL;
    fclose(fp);
}
void add()
{   printf("���������0 �˳�add\n");
    char bh[10];
char mz[10];
    double jg;
    struct medicine *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(scanf("%s",&bh)==1&&bh!="0")
    {   struct medicine * q=(struct medicine *)malloc(sizeof(struct medicine));
        q->next=NULL;
        strcpy(q->num,bh);
        scanf("%s %lf",&q->name,&q->price);
        p->next=q;
        p=q;
    }
    p->next=NULL;
}