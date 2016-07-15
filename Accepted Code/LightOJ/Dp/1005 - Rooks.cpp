#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

#define mx 1002
#define INF 1000*52
using namespace std;

long long fact[22];
long long ncr[32][32];

long long calcNCR(int n, int r)
{
    if(ncr[n][r]!=-1) return ncr[n][r];
    if(n==r) return 1;
    if(r==1) return n;

    return ncr[n][r] = calcNCR(n-1,r-1) + calcNCR(n-1,r);
}

long long rock(int n, int k)
{
    if(n<=18) return (fact[n] / fact[n-k])*calcNCR(n,k);

    long long mul = 1;
    for(long long i = n ; i>n-k ; i--)
        mul *= i;

    return mul*calcNCR(n,k);

}

int main()
{

    int test;
    scan(test);

    fact[1] = 1;
    fact[0] = 1;
    for(int i = 2; i<= 18 ; i++ )
        fact[i] = fact[i-1] *i;

    memset(ncr,-1, sizeof(ncr));

    for(int t  = 1 ; t<= test ; t++ )
    {
        int n,k;
        scan(n);
        scan(k);

        printf("Case %d: ",t);
        if(k>n)
            printf("0\n");
        else if(k==0)
            printf("1\n");
        else if(k==1)
        {
            printf("%lld\n",(long long)(n*n));
        }
        else
        {

            printf("%lld\n",rock(n,k));
        }
    }
}

