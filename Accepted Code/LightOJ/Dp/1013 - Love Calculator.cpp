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
    return (bool) (N & (1<<pos ) ) ;
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

string A,B;
int lena, lenb;
LL dp[61][33][33] ;
int d[33][33];

int lcs(int i, int j)
{
    int &ret = d[i][j];
    if(ret!=-1) return ret ;
    ret = 0;

    if(i==lena || j==lenb) return 0;

    if(A[i]==B[j])
    {
        ret = 1 + lcs(i+1, j+1) ;
    }
    else
    {
        ret = max(lcs(i+1,j) , lcs(i,j+1)) ;
    }
    return ret;
}

LL uniqueString(int l, int i, int j)
{
    LL &ret = dp[l][i][j] ;
    if(ret !=-1) return ret;

    ret = 0;

    if(l==0 )
    {
        if(i==0 && j==0) return ret = 1;
        else return ret = 0;
    }

    if(l && (!i && !j)) return ret = 0;


    if(i==0)
    {
        ret += uniqueString(l-1, i, j-1);
    }
    else if(j==0)
    {
        ret += uniqueString(l-1,i-1,j);
    }

    else if(A[i-1]==B[j-1])
    {
        ret += uniqueString(l-1, i-1, j-1) ;
    }
    else
    {
        ret += uniqueString(l-1,i-1,j) + uniqueString(l-1, i, j-1) ;
    }

    return ret;
}


int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        mem(d, -1) ;
        mem(dp,-1) ;
        cin >> A >> B;
        lena= A.size();
        lenb = B.size() ;
        int l = lcs(0,0) ;
        LL ret = uniqueString(lena + lenb - l , lena, lenb );
        printf("Case %d: %d %lld\n",t,lena + lenb - l,ret);
    }

    return 0;
}

