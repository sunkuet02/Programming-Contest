#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if((a==0 && b==0 && c==0 )|| (a==1 && b==1 && c==1))
            printf("*\n");
        if((a==0 && b==0 && c==1 )|| (a==1 && b==1 && c==0))
            printf("C\n");
        if((a==0 && b==1 && c==0 )|| (a==1 && b==0 && c==1))
            printf("B\n");
        if((a==0 && b==1 && c==1 )|| (a==1 && b==0 && c==0))
            printf("A\n");
    }
    return 0;

}
