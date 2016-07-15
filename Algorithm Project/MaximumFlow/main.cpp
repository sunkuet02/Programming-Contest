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
#define LL long long int
#define mx 100
#define sz 100005
#define mod 1000000007
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p) { T f = 1 ; for(int i=1 ; i<=p ; i++) f*=base; return f; }
template <typename T>  string NumberToString ( T Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}

int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

/**************************Implementation*****************************/

vector<int> graph[mx] ;
int parent[mx];
int capacity[mx][mx] ;
int flowPassed[mx][mx] ;
int curpathcapacity[mx] ;

int bfs(int source, int destin)
{
    memset(parent, -1, sizeof parent);
    memset(curpathcapacity,0,sizeof curpathcapacity);
    queue<int> q;
    q.push(source) ;
    curpathcapacity[source] = 2000 ;
    parent[source] = -2;
    while(!q.empty())
    {
        int u = q.front() ;
        q.pop();
        rep0(i, graph[u].size())
        {
            int v = graph[u][i];

            if(parent[v]==-1)
            {
                if(capacity[u][v] - flowPassed[u][v]> 0)
                {
                    parent[v] = u;
                    curpathcapacity[v] = min(curpathcapacity[u], capacity[u][v] - flowPassed[u][v]) ;
                    if(v==destin)
                        return curpathcapacity[v];
                    q.push(v);
                }
            }
        }
    }
    return 0 ;
}

int edmondKarp(int source,int destin)
{
    int maxFlow = 0 ;
    while(1)
    {
        int flow = bfs(source,destin);
        if(!flow) break;

        maxFlow += flow ;

        int cur = destin ;

        while(cur !=source)
        {
            int prev = parent[cur] ;

            flowPassed[prev][cur] += flow;
            flowPassed[cur][prev] -= flow;
            cur = prev;
        }
    }

    return maxFlow;
}

int main()
{

    int no, edge;
    scan(no);

    int source, destin;
    scan(source);scan(destin); scan(edge) ;

    while(edge--)
    {
        int u,v, cost;
        scan(u);scan(v);scan(cost);
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] = cost ;
    }

    int maxFlow = edmondKarp(source,destin);

    cout << maxFlow << endl;
}
