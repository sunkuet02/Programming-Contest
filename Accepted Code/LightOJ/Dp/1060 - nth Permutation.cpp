/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mxx 100005
#define sz 1000002
#define mod 1000000007
#define MAX 1000005
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
/*********************temp_Definition *************************/
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

/****************************Implementation************************/
char s[25] ;
int arr[30] ;
LL n;
LL fact[21] ;


void calfact()
{
    fact[0]=1;
    for(int i =1 ; i<=20; i++ )
        fact[i] = fact[i-1]*i;
}
bool possible(LL n )
{
    LL sum = 0 ;
    LL lo = 1L;
    for(int i = 0; i<=25; i++)
    {
        sum += arr[i];
        lo *= fact[arr[i]] ;
    }
    if(fact[sum]/ lo < n) return false;

    return true;
}
LL retVal()
{
    LL sum = 0 ;
    LL lo = 1L;
    for(int i = 0; i<=25; i++)
    {
        sum += arr[i];
        lo *= fact[arr[i]] ;
    }
    return (fact[sum]/ lo) ;

}


int main()
{
    //READ();
    calfact();
    int test;
    sc(test);
    rep(t,1,test)
    {
        mem(arr,0) ;
        scanf("%s",s) ;

        for(int  i = 0 ; s[i]!='\0' ; i++ ) arr[s[i]-'a'] ++ ;

        scll(n) ;

        printf("Case %d: ",t);

        if(!possible(n))
        {
            printf("Impossible\n");
            continue ;
        }

        for(int  i = 0 ; s[i]!='\0' ; i++ )
        {
            rep(j, 0, 25)
            {
                if(arr[j])
                {
                    arr[j] -- ;
                    LL res = retVal();

                    if(res < n)
                    {
                        arr[j] ++ ;
                        n -= res; continue;
                    }
                    else
                    {
                        s[i] = char(j + 'a');
                        break;
                    }

                }
            }
        }
        puts(s);



    }
}

