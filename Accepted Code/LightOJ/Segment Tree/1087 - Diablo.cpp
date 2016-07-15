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
#define sz 100005
#define mod 1000000007
#define MAX 1000005
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
int n;

struct node
{
    int val,cnt ;
}tree[sz*6];

void clearTree()
{
    rep(i,0,6*100005 + 1)
    {
        tree[i].cnt = 0 ;
    }
}
/*
void buildTree(int no, int b, int e)
{
    if(b==e)
    {
        tree[no].cnt[1] = tree[no].cnt[2] = tree[no].lazy = 0 ;
        tree[no].cnt[0] = 1;
        return ;
    }
    int mid = (b+e)/2;
    buildTree(no*2, b , mid );
    buildTree(no*2 +1 , mid +1 , e) ;

    tree[no].cnt[0]  = tree[no*2].cnt[0] + tree[no*2+1].cnt[0] ;
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
    tree[no].lazy %=3;
    tree[no*2].lazy += tree[no].lazy ;
    tree[no*2+1].lazy += tree[no].lazy ;
    for(int i = 0 ; i< tree[no].lazy ; i++ )
    {
        swapValues(no*2);
        swapValues(no*2+1);
    }
    tree[no].lazy = 0 ;
}
*/
void update(int no , int b, int e, int i, int j, int val,int cnt)
{
    if(b > j || e<i )  return ;

    if(b>=i && e<=j )
    {
        tree[no].val = val;
        tree[no].cnt = cnt;
        return;
    }

    int mid = (b+e)/2;
    update(no*2, b , mid , i , j,val,cnt);
    update(no*2 +1 , mid +1 , e , i, j,val,cnt) ;

    tree[no].cnt = tree[no*2].cnt + tree[no*2+1].cnt;
}


int queryTree(int no, int b, int e, int i, int j)
{
    if(b==e)
    {
        tree[no].cnt = 0;
        update(1,1,150005, b,e,tree[no].val,0);
        return tree[no].val ;
    }

    int mid = (b+e)/2;

    if( (tree[no*2].cnt < i ))
    {
        //cout <<tree[no].cnt <<   " r " << b << ends << e << endl;
        return queryTree(no*2 +1 , mid +1 , e , i -tree[no*2].cnt ,j - tree[no*2].cnt) ;
    }
    else //if(tree[no].cnt < i || tree[no*2].cnt ==0)
    {
        //cout <<tree[no].cnt <<  " l " << b << ends << e << endl;
        return queryTree(no*2, b , mid , i , j);
    }
    /*
    else
    {
        if(tree[no*2+1].cnt ==0)
        {
            cout << "l " << b << ends << e << endl;
            return queryTree(no*2, b , mid , i , j);
        }
        else
        {
            cout << "r " << b << ends << e << endl;
            return queryTree(no*2 +1 , mid +1 , e , i, j) ;
        }
    }
    */
}

/****************************Implementation************************/


int main()
{
    //Read;
    int test;
    sc(test);
    rep(t,1,test)
    {
        int q;
        sc(n);sc(q) ;
        clearTree();

        int noCount = n ;
        int curPos = n+1;
        rep(i,1,n)
        {
            int a;
            sc(a);
            update(1,1,150005, i,i,a,1);
        }

        printf("Case %d:\n",t);
        //cout << n << ends << q << endl;

        while(q--)
        {
            char ch;
            int p;
            getchar();
            scanf("%c %d",&ch,&p);
            //cout << ch << ends << p << endl;
            if(ch == 'c')
            {
                if(noCount<p)
                {
                    printf("none\n");
                }
                else
                {
                    int ret = queryTree(1,1,150005,p,p);
                    printf("%d\n",ret);
                    noCount -- ;
                }
            }
            else
            {
                update(1,1,150005,curPos,curPos,p,1);
                curPos ++ ;
                noCount ++ ;
            }
        }
    }
}
