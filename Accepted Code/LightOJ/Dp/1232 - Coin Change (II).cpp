#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

#define mx 10002
#define INF 100000007
using namespace std;


//int coin(int i, int rem)
//{
//    if(rem == 0) return 1;
//    else if(i>=n) return 0;
//    else if(arr[i]>rem) return 0;
//    int & val = dp[i][rem];
//    if(val!=-1) return val;
//    else val = 0 ;
//    rep0(j,countCoin[i]+1)
//    {
//        val = (val + coin(i+1,rem - arr[i]*j))%INF;
//    }
//    return val;
//}

int main()
{
    //READ();
    int test;
    int arr[mx],dp[mx];
    scan(test);
    rep1(t,test)
    {
        int m,n;
        scan(n);
        scan(m);
        rep0(i,n)
        {
            scan(arr[i]);
        }

        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        rep0(i,n)
        {
            rep(j, arr[i], m)
            {
                dp[j] =  (dp[j]+ dp[j-arr[i]]) % 100000007;
            }
        }

        printf("Case %d: %d\n",t,dp[m]%100000007);

    }


}

