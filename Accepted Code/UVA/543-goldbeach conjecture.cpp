#include<iostream>
#include<cmath>
#include<cstdio>
#define MAX 1000000
using namespace std;
bool prime[MAX];
void seive()
{
    prime[2] = true;
    for(int i=3;i<=MAX;i+=2)
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
    int a;
    while((cin>>a)&&a)
    {
        int b=3,c=a-3;
        for(;;)
        {
            if(prime[b] && prime[c])
            {
                printf("%ld = %ld + %ld\n",a,b,c);
                break;
            }
            b+=2;
            c-=2;
            if(b>c) break;

        }
        if(b>c)
                printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
