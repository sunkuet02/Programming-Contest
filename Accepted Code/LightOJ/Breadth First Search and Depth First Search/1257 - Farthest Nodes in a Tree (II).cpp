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
#define Pi  acos(-1.0)
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
/****************************Implementation************************/

vector<int> graph[30005], cost[30005];

int dist[5][30005];
bool visited[30005];

int bfs(int n, int source, int disMark)
{
    queue<int> q;
    q.push(source);
    mem(visited, false);
    visited[source] = true;
    dist[disMark][source] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0 ; i< graph[u].size() ; i++ )
        {
            int v = graph[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                dist[disMark][v] = dist[disMark][u] + cost[u][i];
                q.push(v);
            }
        }
    }
    int mx = -1, mxnode = 0;
    rep(i,0,n-1)
    {
        if(dist[disMark][i] > mx)
        {
            mx = dist[disMark][i];
            mxnode = i;
        }
    }
    return  mxnode;
}

int main()
{
    //Read;
    int test;
    sc(test);
    rep(t,1,test)
    {
        mem(dist, 0);
        int n;
        sc(n);

        rep(i,1,n-1)
        {
            int u, v, w;
            sc(u);sc(v);sc(w);
            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int mostDistNode = bfs(n, 0, 0);
        int secDistNode  = bfs(n, mostDistNode, 1);
        int lastDistNode = bfs(n, secDistNode, 2);

        printf("Case %d:\n", t);
        rep(i,0,n-1)
        {
            printf("%d\n", max(dist[1][i], max(dist[2][i], dist[0][i]) ));
            graph[i].clear();
            cost[i].clear();
        }
    }
}

