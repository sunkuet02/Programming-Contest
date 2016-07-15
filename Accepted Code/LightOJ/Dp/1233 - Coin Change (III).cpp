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
#define mx 50005
#define sz 1000002
#define mod 1000000007
#define MAX 10000005
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

int arr[100005];
int taken[100005] ;
int n,m;
int A[106], C[106];

int Count()
{
    arr[0] = -1;
    rep1(i,n)
    {
        int cur = A[i];

        rep(j,A[i],100005)
        {
            if(!arr[j] && arr[j-A[i]])
            {
                if(arr[j-A[i] ] != cur && C[i])
                {
                    arr[j] = cur;
                    taken[j] = 1 ;
                }
                else if(taken[j-A[i]] < C[i])
                {
                    taken[j] = taken[j-A[i]] + 1 ;
                    arr[j] = cur;

                }

            }
        }
    }
    int cnt = 0 ;
    rep1(i,m) if(arr[i]) cnt++ ;
    return cnt;
}

int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        mem(arr,0);
        mem(taken, 0);
        scan(n);scan(m);
        rep1(i,n) scan(A[i]);
        rep1(i,n) scan(C[i]);

        int ret = Count();
        printf("Case %d: %d\n",t,ret) ;

    }
}
