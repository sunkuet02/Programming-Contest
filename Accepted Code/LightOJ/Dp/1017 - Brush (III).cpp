   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
#define LL long long int
#define MAX 10000005
#define sz 100005
#define mod
using namespace std;

typedef pair<int, int> pii;


template<class T> inline T power(T base, int p) { T f = 1 ; for(int i=1 ; i<=p ; i++) f*=base; return f; }

int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

using namespace std;

int arr[105],dp[104][104];
int n,w,k;

int brush(int a, int b, int k)
{
    if(!k || b<a) return 0 ;
    int & res = dp[a][k];
    if(res !=-1) return dp[a][k];

    int j = a;
    int cnt = 1;
    res = 0 ;
    rep(i, a+1,b)
    {
        if(arr[i]-arr[a] <= w)
        {
            j = i;
            cnt ++ ;
        }
        else
            break;
    }

    res = max ( cnt + brush(j+1, b,k-1) , brush(a+1,b, k) );

    return res ;

}


int main()
{
    //READ();
    int test;
    scan(test);
    for(int t = 1; t<= test; t++)
    {
        memset(dp, -1 , sizeof(dp));

        int x,y;
        scan(n);scan(w);scan(k);
        rep0(i,n)
        {
            scan(x);scan(y);
            arr[i] = y;
        }
        sort(arr,arr+n);


        int cnt = brush(0,n-1,k);

        printf("Case %d: %d\n",t,cnt);
    }

}

