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
#define INF 100000007
using namespace std;

int arr[mx],dp[mx][mx],countCoin[mx];
int n;

int coin(int i, int rem)
{
    if(rem == 0) return 1;
    else if(i>=n) return 0;
    else if(arr[i]>rem) return 0;
    int & val = dp[i][rem];
    if(val!=-1) return val;
    else val = 0 ;
    rep0(j,countCoin[i]+1)
    {
        val = (val + coin(i+1,rem - arr[i]*j))%INF;
    }
    return val;
}

int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        int m;
        scan(n);
        scan(m);
        rep0(i,n)
        {
            scan(arr[i]);
        }
        rep0(i,n)
        {
            scan(countCoin[i]);
        }
        memset(dp,-1,sizeof(dp));

        int ret = coin(0,m);
        printf("Case %d: %d\n",t,ret);

    }


}

