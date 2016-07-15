#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

#define mx 17
#define INF 999999999
using namespace std;

int arr[mx][mx] , dp[mx][1<<mx];
int n;

int marrige(int i,int mask)
{
    if(i>=n) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask] ;
    int ans = -1;
    rep0(j,n)
    {
        if(!checkbit(mask,j))
            ans = max(ans , marrige(i+1,setbit(mask,j)) + arr[i][j]);
    }

    return dp[i][mask] = ans;
}


int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        scan(n);
        rep0(i,n)
        {
            rep0(j,n)
            {
                scan(arr[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",t,marrige(0,0));
    }


}

