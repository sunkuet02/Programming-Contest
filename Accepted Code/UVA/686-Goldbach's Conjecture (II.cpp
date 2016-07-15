#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAX 10000000
using namespace std;
bool prime[MAX];
void seive()
{
    for(int i=2;i<=MAX;i++)
        prime[i]=true;
    for(int i=4;i<=MAX;i+=2) prime[i]=false;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }

}
int main()
{
    seive();
    int num;
    while((cin>>num)&& num)
    {
        if(num==4)
        {
            cout<<1<<endl;
            continue;
        }
        int a=3;
        int b=num-3;
        int countt=0;
        for(;;)
        {
            if(prime[a]&& prime[b])
                if(a+b==num)
                        countt++;
                a+=2;
                b-=2;
                if(a>b) break;
        }
        cout<<countt<<endl;
    }

    return 0;
}

