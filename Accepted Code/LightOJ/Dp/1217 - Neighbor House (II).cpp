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
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mx 100005
#define sz 1000002
#define mod 1000000007
#define MAX 1e9
#define inf INT_MAX
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p)
{
    T f = 1 ;
    for(int i=1 ; i<=p ; i++) f*=base;
    return f;
}
template <typename T>  string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int setbit(int N,int pos)
{
    return N = N|(1<<pos);
}
int resetbit(int N, int pos)
{
    return N = N & ~(1<<pos) ;
}
bool checkbit(int N,int pos)
{
    return (bool) (N & 1<<pos) ;
}

/*********************nCr**************************/
/*
int ncr[1005][1005];
int NCR()
{
    rep0(i,1003)
    {
        ncr[i][0] = 1;
    }
    rep1(i,1003)
    {
        rep1(j,1003)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %=mod;
        }
    }
}
*/

/****************************ExtendedEuclid&ModularInverse****/

pii extendedEuclid(int a,int b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
int modularInverse(int a,int m)
{
    pii ret = extendedEuclid(a,m);
    return ret.first % m ;
}

/****************************Implementation************************/

int dp[3][1005] ;
int n;
int arr[1005] ;

int cal(bool isfirst, int pos)
{
    if(pos ==n && !isfirst) return arr[pos];
    else if(pos >=n) return 0;

    int & ret = dp[isfirst][pos ];
    if(ret !=-1) return ret ;
    if(pos ==1)
    {
        return ret = max( arr[pos ] + cal(true ,pos + 2 ), cal(false, pos + 1) );
    }
    return ret = max( (arr[pos] + cal(isfirst , pos + 2)),cal(isfirst , pos + 1) );
}

int main()
{
    int test;
    scan(test);

    rep1(t,test)
    {
        mem(dp,-1);
        scan(n);
        rep1(i,n) scan(arr[i]);


        printf( "Case %d: %d\n",t,cal(false,1) );
    }
}

