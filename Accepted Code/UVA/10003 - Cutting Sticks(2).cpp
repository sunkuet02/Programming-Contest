#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);

#define mx 55
#define INF 999999999
using namespace std;

int arr[mx];
int dp[mx][mx];

int cutSticks(int start, int end)
{
    if(end-start==1) return 0;
    if(dp[start][end]!= -1) return dp[start][end];
    int minimum = INF;
    for(int i = start+1; i<end ; i++  )
    {
        int m = cutSticks(start,i) + cutSticks(i , end) + arr[end] - arr[start];
        if(m<minimum)
            minimum = m;
    }
    return dp[start][end] = minimum;
}
int main()
{

    int l;
    while(scan(l) && l)
    {
        int n;
        scan(n);
        rep1(i,n)
            scan(arr[i]);
        memset(dp,-1,sizeof(dp));

        arr[0] = 0 ;
        arr[n+1] = l;

        printf("The minimum cutting is %d.\n",cutSticks(0,n+1));
    }
    return 0;
}
