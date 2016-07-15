
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int contain[105];
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++)
    {
        int n;
        memset(contain,0,sizeof(contain));
        bool isans = true;
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
            {
                int a;
                scanf("%d",&a);
                contain[a]++;
                if(contain[a]>n)
                    isans = false;

            }
        if(isans)
            printf("Case %d: yes\n",t);
        else
            printf("Case %d: no\n",t);
    }
}
