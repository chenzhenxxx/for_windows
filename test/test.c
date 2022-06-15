#include<stdio.h>
int main()
{
    FILE* fp;
    fp=fopen("C:\\Users\\DELL\\Desktop\\mycode\\my-test-git\\test\\2.txt","a+");
    if(fp==NULL)
    {
        printf("sddsds");
    }
    fprintf(fp,"hello");
}