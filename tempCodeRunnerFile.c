#include <stdio.h>
struct queue
{
    int lou;
};
int book[200];
int count;
main()
{   struct queue que[40001];
    int n,a,b;
    int i,flag=0;
    int step[201];
    scanf("%d %d %d",&n,&a,&b);
    for(i=1;i<=n;i++)
    scanf("%d",&step[i]);

    int head=1;
    int tail=1;
    que[tail].lou=a;
    tail++;

    while(head<tail)
    {   int tx;
        int m=1;
        for(i=0;i<2;i++)
        { m*=-1;
        tx=que[head].lou+m*step[que[head].lou];
        if(tx>0&&book[tx]==0)
        {  int m=book[que[head].lou]+1;
             book[tx]=m;
             que[tail].lou=tx;
             tail++;
            if(tx==b)
           {
               flag=1;
               break;
           }
        }
        }
        head++;
    }

    if(flag==0)
    printf("-1");
     else
     printf("%d",book[b]);

    

}