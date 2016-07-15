#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a,b,c;

    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        int cnt = 0;
        while(b!=c)
        {
            b = (b+1)/2;
            c = (c+1)/2;
            cnt++;

        }
        cout<<cnt<<endl;

    }
}

