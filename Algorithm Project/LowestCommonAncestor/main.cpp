#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define sz 100005

using namespace std;

int table [mx][24];
int parent[mx];
int level[mx];
vector<int> graph[mx];
bool visited[mx];

void dfs(int u, int v, int depth)
{
    if(visited[u]) continue;
    visited[u] = true;
    parent[v] = u;
    level[v] = depth;

    for(int i = 0 ; i< graph[u].size() ; i++ )
    {
        int  child = graph[u][i];
        if(child==from ) continue;
        dfs(v,child, depth +1);
    }
}

void lca_init()
{

}

void take_input()
{
    memset(visited, false, sizeof(visited));
    dfs(0,0,0);

}
int main()
{

    return 0;
}
