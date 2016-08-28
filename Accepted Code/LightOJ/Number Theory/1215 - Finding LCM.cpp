/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define Read freopen("input.txt","r",stdin);
#define Write freopen("output.txt","w",stdout);
#define mem(a,val) memset(a,val, sizeof(a) );
#define LL long long int
#define mxx 65536
#define sz 200005
#define MAX 1000002

using namespace std;

typedef pair<int, int> pii;


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
int noofsetbits(int N)
{
    return __builtin_popcount (N);
}
/*****************Seive Prime********************/
/*
bool prime[MAX];
void seive()
{
    for(int i=2;i<=MAX;i++)
        prime[i]=true;
    for(int i=4;i<=MAX;i+=2) prime[i]=false;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }
}
*/

/*********************nCr**************************/
/*
long long ncr[1005][1005];
void NCR()
{
    rep0(i,1003)
    {
        ncr[i][0] = 1;
    }
    rep(i,1, 1003)
    {
        rep(j,1,1003)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %=mod;
        }
    }
}
*/

LL bigMod(LL N,LL M,LL MOD)
{
    if(M==0) return 1;

    if((M/2)*2==M)
    {
        LL ret = bigMod(N,M/2,MOD)%MOD;
        return (ret*ret)%MOD;
    }
    else return ((N%MOD)*bigMod(N,M-1,MOD)%MOD)%MOD;
}

LL modInverseBigMod(LL a,LL m)  //a*x=1(mod m)
{
    return bigMod(a,m-2,m);
}

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
    return ( (ret.first % m) + m ) %m ;
}

/*********************temp_Definition *************************/
/*
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


  // Knight Moves
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};
*/

/***************************Implementation*********************/
LL primes[1000005], primeCnt;
vector<LL>divisors, powers;

bool prime[MAX];
void seive()
{
    for(int i=2; i<=MAX; i++)
        prime[i]=true;
    for(int i=4; i<=MAX; i+=2) prime[i]=false;
    for(int i=3; i<=sqrt(MAX); i+=2)
    {
        if(prime[i]==true)
            for(int j=i*i; j<MAX; j+=(2*i))
                prime[j]=false;
    }
    for(int i = 2; i<= MAX ; i++ )
    {
        if(prime[i])
        {
            primes[primeCnt++] = i;
        }
    }
}

void calculateDivisors(LL a, LL b)
{
    for(int i = 0  ; i< primeCnt && (a>1 || b>1); i++ )
    {
        LL p = primes[i];
        int cnta= 0, cntb = 0;
        while(a%p == 0 )
        {
            cnta ++ ;
            a/= p;
        }
        while(b%p == 0 )
        {
            cntb ++ ;
            b/= p;
        }
        if(max(cnta, cntb) > 0)
        {
            divisors.push_back(p);
            powers.push_back(max(cnta, cntb));
        }
    }
}

LL retC(LL L)
{
    LL ret = 1L;
    for(int i = 0 ; i< divisors.size(); i++ )
    {
        int cnt = 0 ;
        while(L % divisors[i]==0)
        {
            cnt ++ ;
            L /=divisors[i];
        }
        if(cnt < powers[i]) return -1;
        else if (cnt > powers[i])
        {
            ret *= power(divisors[i], cnt);
        }
    }
    return ret*L;
}
int main()
{
    seive();
    int test;
    sc(test);

    rep(t,1,test)
    {
        divisors.clear();
        powers.clear();
        LL A,B,L;
        scanf("%lld %lld %lld", &A,&B, &L);
        calculateDivisors(A,B);
        LL ret = retC(L);
        if(ret !=-1)
            printf("Case %d: %lld\n", t, ret);
        else
            printf("Case %d: impossible\n", t);
    }

}
