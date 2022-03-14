#include<stdio.h>
char a[110][110];
int book[110][110];
int pos[8][2]={{0,-1},{1,1},{1,-1},{1,0},{-1,0},{-1,-1},{0,1},{-1,1}};
char p[8]="yizhong";
int n;
void dfs(int x,int y,int k)
{
	int c=x,d=y,i,j;
	for(i=0;i<7;i++)
	{
		if(p[i]!=a[c][d])
		return;
		c+=pos[k][0];
		d+=pos[k][1];
	}
	for(j=0;j<7;j++)
	{
		book[x][y]=1;
		x+=pos[k][0];
		y+=pos[k][1];
	}
}
main()
{
	int i,j,k;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{  
		for(j=1;j<=n;j++)
	   scanf("%c",&a[i][j]);
       getchar();
       getchar();
	   
		
	}

		for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(a[i][j]=='y')
		{
			for(k=0;k<8;k++)
			dfs(i,j,k);
		}
	}
 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
	{
		if(book[i][j]==1)
		printf("%c",a[i][j]);
		else
		printf("*");
	
	}
    printf("\n");
	}

}