#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int isprime(long int m)
{
    if(m%2==0) return 0;
    for(int i=3;i<=sqrt(m);i+=2)
        if(m%i==0) return 0;
    return 1;
}
int main()
{
    long int a,m,b,c,d,i,j;
    map<int,bool>mp;
    for(j=0;j<=10000;j++)
    {
        m=j*j+j+41;
        if(isprime(m))
        {
            mp[j]=true;
        }
        else mp[j]=false;
    }
    while(scanf("%ld %ld",&a,&b)!=EOF)
    {
        int count=0;
        for(i=a;i<=b;i++)
        {
            if(mp.find(i)->second) {count++;}
        }
        d=b-a+1;
        double (ans)=double(count)/double(d);
        ans=ans*100.0+ 1e-8;
        printf("%.2lf\n",ans);
    }
    return 0;
}
