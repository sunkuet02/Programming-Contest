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
#define sz 10005
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
int noofsetbits(int N){ return __builtin_popcount (N); }
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
/*
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


  // Knight Moves
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};
*/

/****************************Implementation************************/
string str;
LL dp[1<<16][20] ;
int numval[75],base, k,n;
int baseval[20];

void assignNum()
{
    int k = 0;
    for(int i = '0'; i<='9'; i++ )
        numval[i]=k++ ;
    for(int i = 'A'; i<='F'; i++ )
        numval[i]=k++ ;
}

void basevalue(int n)
{
    baseval[0] = 1L ;
    for(int i = 1 ; i<=17; i++ )
    {
        baseval[i] = (baseval[i-1] * base)%k;
    }

}
LL cal(int mask,int modval)
{
	if(mask==(1<<n)-1)
    {
        if(modval==0) return 1;
        else return 0;
    }

    LL & ret = dp[mask][modval];

    if(ret!=-1) return ret ;

    ret = 0 ;

    int pos = noofsetbits(mask);

    for(int i = 0 ; i< n; i++ )
    {
        if(!checkbit(mask,i))
        {
            ret += cal(setbit(mask, i) , (modval + baseval[pos] * numval[(int)(str[i])])%k );
        }
    }

    return ret ;

}


int main()
{
    //READ();
    assignNum();

    int test;
    sc(test);
    rep(t,1, test)
    {
        mem(dp,-1);
        sc(base);sc(k);
        cin >> str;
        n = str.size();
        basevalue(n);

        LL res = cal(0,0);
        printf("Case %d: %lld\n",t,res);
    }
}

