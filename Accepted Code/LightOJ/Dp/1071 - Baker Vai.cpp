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
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mxx 100005
#define sz 1429440/2
#define mod 1000000007
#define MAX 2005
#define inf INT_MAX

using namespace std;

typedef pair<int , int> pii;


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
/********************Segment Tree *************************/
/*
int n;

struct node
{
    int val,cnt ;
}tree[sz*3];

void clearTree()
{
    rep(i,0,3*sz + 1)
    {
        tree[i].cnt = 0 ;
    }
}
void buildTree(int no, int b, int e)
{
    if(b==e)
    {
        tree[no].cnt = 1;
        tree[no].val = 2*b -1;

        return ;
    }
    int mid = (b+e)/2;
    buildTree(no*2, b , mid );
    buildTree(no*2 +1 , mid +1 , e) ;

    tree[no].cnt  = tree[no*2].cnt + tree[no*2+1].cnt ;
}
/*
void swapValues(int no)
{
    int temp = tree[no].cnt[2];
    tree[no].cnt[2] = tree[no].cnt[1];
    tree[no].cnt[1] = tree[no].cnt[0];
    tree[no].cnt[0] = temp;
}
*/
/*
void pushdown(int no)
{
    tree[no*2].cnt += tree[no].cnt ;
    tree[no*2+1].cnt += tree[no].cnt ;
    tree[no].cnt = 0 ;
}

void update(int no , int b, int e, int i, int j,int cnt)
{
    if(b > j || e<i )  return ;

    if(b>=i && e<=j )
    {
        tree[no].cnt = cnt;
        return;
    }
    //pushdown(no);
    int mid = (b+e)/2;
    update(no*2, b , mid , i , j,cnt);
    update(no*2 +1 , mid +1 , e , i, j,cnt) ;

    tree[no].cnt = tree[no*2].cnt + tree[no*2+1].cnt;
}

bool f ;

int queryTree(int no, int b, int e, int i, int j)
{
    if(b==e)
    {
        return tree[no].val ;
    }

    int mid = (b+e)/2;

    if( (tree[no*2].cnt < i ))
    {
        //if(f)
        //cout <<tree[no].cnt <<   " r " << b << ends << e << endl;
        return queryTree(no*2 +1 , mid +1 , e , i -tree[no*2].cnt ,j - tree[no*2].cnt) ;
    }
    else //if(tree[no].cnt < i || tree[no*2].cnt ==0)
    {
        //cout <<tree[no].cnt <<  " l " << b << ends << e << endl;
        return queryTree(no*2, b , mid , i , j);
    }

}

*/
/****************************Implementation************************/
int m , n ;
int dp[205][103][103] ;
int x[103][103];
int Inf = 20*101*101;

int cal(int step, int row1 , int row2)
{
    if(step == n+m-2)
    {
        if(row1== m-1 && step - row1 == n-1 && row1 == row2)
        {
            return x[m-1][n-1] ;
        }

        return -Inf;
    }

    int & ret = dp[step][row1][row2];

    if(ret!=-1) return ret ;

    if(step- row1 < n && step - row2 <n)
        ret = max(ret, cal(step+1, row1, row2));

    if(row1 + 1 < m && step-row1< n) ret = max(ret, cal(step + 1, row1 + 1, row2));
    if(row2 + 1 < m && step-row2< n) ret = max(ret, cal(step + 1, row1, row2 + 1));
    if(row1 + 1< m && row2 +1 < m  &&step-row1< n &&  step-row2< n) ret = max(ret, cal(step + 1, row1 + 1, row2 +1));


    if(ret != -1)
    {
        ret += x[row1][step-row1];

        if(row1 != row2)
            ret += x[row2][step-row2];
    }

    return  ret;
}

int main()
{
    int test;
    sc(test);

    rep(t,1,test)
    {
        sc(m);
        sc(n);

        mem(dp, -1);

        rep(i,0,m-1)
        {
            rep(j,0,n-1)
            {
                sc(x[i][j]);
            }
        }
        int ret = cal(0,0,0);
        printf("Case %d: %d\n",t,ret);
    }
}
