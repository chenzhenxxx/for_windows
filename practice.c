 int num[10];
#include<stdio.h>
int main()
{
    char a[2000];
   

    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++)
      num[a[i]-'0']++;

    for(int i=0;i<10;i++)
      {
          if(num[i]!=0)
        printf("%d:%d\n",i,num[i]);
      }
           
}