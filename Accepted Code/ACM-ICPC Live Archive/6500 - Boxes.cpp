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
#define mod 10056
#define MAX 100005

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
/********************Segment Tree *************************/
/*
int n;

struct node
{
    int val ;
}tree[sz*3];

void clearTree()
{
    rep(i,0,3*sz + 1)
    {
        tree[i].val = 0 ;
    }
}
/*
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

void swapValues(int no)
{
    int temp = tree[no].cnt[2];
    tree[no].cnt[2] = tree[no].cnt[1];
    tree[no].cnt[1] = tree[no].cnt[0];
    tree[no].cnt[0] = temp;
}
void pushdown(int no)
{
    if(tree[no].val ==0) return;

    tree[no*2].val = tree[no].val ;
    tree[no*2+1].val = tree[no].val ;
    tree[no].val = 0 ;
}

void update(int no , int b, int e, int i, int j,int val)
{
    if(b > j || e<i )  return ;

    if(b>=i && e<=j )
    {
        tree[no].val = val;
        return;
    }
    pushdown(no);
    int mid = (b+e)/2;

    update(no*2 , b, mid, i, j , val);
    update(no*2+1, mid+1, e, i, j, val);

    if(tree[no*2].val == tree[no*2+1].val)
    {
        tree[no].val = tree[no*2].val;
    }
    else
    {
        tree[no].val = 0 ;
    }
}

int queryTree(int no, int b, int e, int i, int j)
{
    if(b > j || e<i )  return 0;

    if(b>=i && e<=j )
    {
        return tree[no].val;
    }
    pushdown(no);

    int mid = (b+e)/2;

    int left = queryTree(no*2, b, mid, i, j);
    int right = queryTree(no*2+1, mid + 1, e, i, j);

    if(left!=0) return left;
    else if(right!=0) return right;
    else return 0;

}
*/
/****************************Implementation************************/

int grid[105][105];

int main()
{
    //freopen("input.txt", "r", stdin);

    int test;
    sc(test);
    rep(t,1,test)
    {
        int row, col;
        sc(row);sc(col);

        rep(r,1,row)
        {
            rep(c,1,col)
            {
                sc(grid[r][c]);
            }
        }

        int sum = 0 ;
        rep(c, 1, col)
        {
            int cur = row;
            for(int r = row ; r>= 1; r-- )
            {
                if(grid[r][c])
                {
                    grid[r][c] = 0;
                    grid[row][c] = 1;
                    sum += (cur - r);
                    cur -- ;
                }
            }

        }
        cout << sum << endl ;
    }
}
