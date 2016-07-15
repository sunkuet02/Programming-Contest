
/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ freopen("input.txt","r",stdin);
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
int noofsetbits(int N)
{
    return __builtin_popcount (N);
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
int n, m;
vector<int> graph[16005], revgraph[16005];
vector<int> order;
bool visit[16005];
int nocomponent[16005];
int counter = 0 ;

int dfs1(int u)
{
    visit[u] = true;
    for(int i = 0 ; i< graph[u].size() ; i++ )
    {
        if(!visit[graph[u][i] ])
            dfs1(graph[u][i]);
    }
    order.push_back(u);
}

int dfs2(int u)
{
    visit[u] = true;

    for(int i = 0 ; i< revgraph[u].size() ; i++ )
    {
        int v = revgraph[u][i];
        if(!visit[v])
            dfs2(v);
    }
    nocomponent[u] = counter;
}

int main()
{
    //READ

    int test;
    sc(test);
    rep(t,1,test)
    {
        mem(visit,false);
        mem(nocomponent,-1);
        order.clear();
        rep(i,0,16003)
        {
            graph[i].clear();
            revgraph[i].clear();
        }

        sc(n);sc(m);
        rep(i,1,n)
        {
            int a, b;
            sc(a);sc(b);

            if(a<0)
                a*= (-1);
            else
                a+= 8000;
            if(b<0)
                b*=(-1);
            else
                b+=8000;

            int nota, notb;

            if(a<8000)
                nota = a + 8000;
            else
                nota = a- 8000;
            if(b<8000)
                notb = b+8000;
            else
                notb = b - 8000;

            graph[nota].push_back(b);
            graph[notb].push_back(a);

            revgraph[b].push_back(nota);
            revgraph[a].push_back(notb);

        }

        for(int i = 1; i<= m ;i++ )
        {
            if(!visit[i])
                dfs1(i);
        }

        for(int i = 8001 ; i<=m+8000 ; i++ )
            if(!visit[i])
                dfs1(i);

        counter = 0 ;
        mem(visit,false);
        for(int i = order.size() -1; i>=0 ; i--)
        {

            if(!visit[order[i] ])
            {
                counter ++ ;
                dfs2(order[i]);
            }

        }

        bool f = true;
        for(int i = 1; i<= m ; i++ )
        {
            if(nocomponent[i] == nocomponent[i+8000])
            {
                f = false;
                break;
            }
        }

        printf("Case %d: ",t);
        if(!f)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            order.clear();
            for(int i = 1; i<= m; i++ )
            {
                if(nocomponent[i] < nocomponent[i+8000])
                {
                    order.push_back(i);
                }
            }
            printf("%d",order.size());
            for(int i = 0 ; i< order.size(); i++ )
            {
                printf(" %d",order[i]);
            }
            printf("\n");
        }
    }

}
