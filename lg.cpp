#include<iostream>
using namespace std;
int map[50][50];
int book[50];
int n,m,min1,u;
int dis[50];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                map[i][j]=0;
            }else{
                map[i][j]=999999;
            }
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a][b]=c;
    }
    for(int i=1;i<=n;i++){
        dis[i]=map[1][i];
    }
    book[1]=1;
    for(int i=1;i<=n-1;i++){
        min1=999999;
        for(int j=1;j<=n;j++){
            if(dis[j]<min1 && !book[j]){
                min1=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(int v=1;v<=n;v++){
            if(map[u][v]<999999){
                if(dis[v]>dis[u]+map[u][v]){
                    dis[v]=dis[u]+map[u][v];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    return 0;
}