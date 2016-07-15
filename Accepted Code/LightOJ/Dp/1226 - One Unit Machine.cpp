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
#define mx 1000005
#define sz 100005
#define mod 1000000007
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p) { T f = 1 ; for(int i=1 ; i<=p ; i++) f*=base; return f; }
template <typename T>  string NumberToString ( T Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}

int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

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

pii extendedEuclid(LL a,LL b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
LL modularInverse(LL a,LL m)
{
    pii ret = extendedEuclid(a,m);
    return ((ret.first % m ) + m )%m ;
}


/**************************Implement***********************/

int sum[1005];
int arr[1005];
LL fact[mx];

void factcal()
{
    fact[0] = 1 ;
    rep1(i,mx-2)
    {
        fact[i] = fact[i-1]* i ;
        fact[i] %=mod;
    }
}

int main()
{
    factcal();
    int test;
    scan(test);
    rep1(t,test)
    {
        int n ;
        LL res = 1;
        sum[0] = 0 ;
        scan(n);

        rep1(i,n)
        {
            scan(arr[i]);
            sum[i] = sum[i-1] +  arr[i] ;
        }
        rep(i,2,n)
        {
            LL f = fact[sum[i]-1];
            LL ft = fact[sum[i]-arr[i] ] * fact[arr[i] -1 ];
            ft %= mod;

            res = res * ((f * modularInverse(ft,mod))%mod )  ;
            res%=mod;
        }
        printf("Case %d: %lld\n",t,res%mod);
    }
}
