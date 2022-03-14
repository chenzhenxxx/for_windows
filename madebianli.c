#include <stdio.h>
struct queue
{
    int x;
    int y;
    
};
int book[401][401];
main()
{
    struct queue que[160010];
    int n,m,x,y,head,tail,i,j;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for( i=1;i<=n;i++)
    for( j=1;j<=m;j++)
    book[i][j]=-1;

    book[x][y]=0;
    head=1;
    tail=1;
    que[tail].x=x;
    que[tail].y=y;
    tail++;

    while(head<tail)
    {  int tx,ty;
        int next[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
        for( i=0;i<8;i++)
        {
            tx=que[head].x+next[i][0];
            ty=que[head].y+next[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&book[tx][ty]==-1)
            {
                int step=book[que[head].x][que[head].y]+1;
            
           
                 que[tail].x=tx;
                 que[tail].y=ty;
                 book[tx][ty]=step;
                  tail++;
                
            
            }
        }
        head++;
    }

     for(int i=1;i<=n;i++)
     {

      for(int j=1;j<=m;j++)
     {

      printf("%-5d ",book[i][j]);
     }
      printf("\n");
     }
   
}