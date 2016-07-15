#include<bits/stdc++.h>

using namespace std;

long long bigMod(long long b, long long  p , long long m)
{
    if(p==0)
        return 1; 
    else if(p%2==1)
    {
        return ((bigMod(b,p-1,m)%m)*(b%m))%m;
    }
    else
    {
        return ((bigMod(b,p/2,m)%m)*(bigMod(b,p/2,m)%m)%m);
    }
}

int main()
{
    long long b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)!=EOF)
    {
        long long re;
        if(b==0)
            re = 0 ;
        else
            re= bigMod(b,p,m);
        cout<<re<<endl;
    }
    return 0;
}