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

int Lf[mx], Ll [mx] ;
int I[mx];
int n;
int arr[mx];

int LIS()
{
    I[0] = -inf;
    rep1(i,n) I[i] = inf;
    int lislen = 0 ;

    rep1(i,n)
    {
        int lo = 0 , hi = lislen ;

        while(lo <=hi)
        {
            int mid = (lo + hi)/2;

            if(I[mid] < arr[i])
                lo = mid  + 1;
            else
                hi = mid -1 ;

        }

        I[lo] = arr[i];
        Lf[i] = lo;
        if(lislen < lo)
            lislen = lo;
    }

}

int LISrev()
{
    I[0] = -inf;
    rep1(i,n) I[i] = inf;
    int lislen = 0 ;

    rep1(i,n)
    {
        int lo = 0 , hi = lislen ;

        while(lo <=hi)
        {
            int mid = (lo + hi)/2;

            if(I[mid] < arr[i])
                lo = mid  + 1;
            else
                hi = mid -1 ;

        }

        I[lo] = arr[i];
        Ll[i] = lo;
        if(lislen < lo)
            lislen = lo;
    }

}
int main()
{
    int test;
    scan(test);

    rep1(t,test)
    {
        scan(n);
        rep1(i,n)
        {
            scan(arr[i]);
        }
        LIS();

        for(int i = 1; i<=n/2; i++ )
        {
            swap(arr[i], arr[n-i+1]);
        }

        LISrev() ;
        for(int i = 1; i<=n/2; i++ )
        {
            swap(Ll[i], Ll[n-i+1]);
        }

        int maximum = 1 , cnt = 0;
        int i = 1, j = n ;
        while(i<=j)
        {
            while(Lf[i]!= maximum && i<=n)
                i ++ ;
            while(Ll[j]!=maximum && j>0)
                j -- ;
            if(i>j) break;
            cnt ++ ;
            maximum ++ ;

        }

        printf( "Case %d: %d\n",t,2*cnt -1 );
    }
}

