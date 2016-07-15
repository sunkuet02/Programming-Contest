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
#define sz 30005
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
/*****************Seive Priem********************/
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

int arr[sz] ;

struct node
{
    int m ;
    int acw;
}tree[sz*3];

void buildTree(int no, int b, int e)
{
    if(b==e)
    {
        tree[no].m = e;
        return ;
    }
    int mid = (b+e)/2;
    buildTree(no*2, b , mid );
    buildTree(no*2 +1 , mid +1 , e) ;

    int pos ;
    if(arr[tree[no*2].m] > arr[tree[no*2+1].m] )
    {
        tree[no].m = tree[no*2+1].m;
    }
    else
    {
        tree[no].m = tree[no*2].m;
    }
}

int queryTree(int no, int b, int e, int i, int j)
{
    if(b > j || e<i )  return -1;

    if(b>=i && e<=j ) return tree[no].m;

    int mid = (b+e)/2;
    int posleft = queryTree(no*2, b , mid , i , j);
    int posright = queryTree(no*2 +1 , mid +1 , e , i, j) ;

    if(posleft!=-1 && posright !=-1)
    {
        if(arr[posleft]< arr[posright])
            return posleft;
        else
            return posright;
    }
    else if(posleft!=-1)
    {
        return posleft;
    }
    else if(posright!=-1)
    {
        return posright;
    }
    else
        return -1;

}


/****************************Implementation************************/
int n ;
int getArea(int i, int j)
{
    if(i==j)
        return arr[i];
    int pos = queryTree(1,1,n , i,j);
    if(pos==-1) return 0;

    return max( (j-i+1)* arr[pos] , max(getArea(i,pos-1), getArea(pos+1,j)));
}


int main()
{
    int test;
    sc(test);

    rep(t,1,test)
    {
        sc(n);

        rep(i,1,n)
        {
            sc(arr[i]);
        }
        buildTree(1,1,n);
        int ret = getArea(1,n);

        printf("Case %d: %d\n",t,ret);
    }
}
