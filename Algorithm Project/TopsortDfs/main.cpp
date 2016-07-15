#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
#define mx 10005
using namespace std;

int t[mx];
int color[mx];
vector<int>graph[mx];
vector<pair<int, int> > v;
int tim;


int dfs_visit(int u)
{
    tim++;
    color[u] = 1;
    for(int i = 0 ; i< graph[u].size() ; i++ )
    {
        int v= graph[u][i];
        if(!color[v])
        {
            dfs_visit(v);
        }
    }
    color[u] = 2;
    tim ++ ;
    t[u] = tim;
}

int dfs(int n)
{
    memset(color, 0 , sizeof(color));

    tim = 0 ;
    for(int i = 1; i<= n ;i++ )
    {
        if(!color[i])
            dfs_visit(i);
    }

}

int main()
{
    READ();
    int test;
    scan(test);
    for(int tt = 0 ; tt<test ; tt++)
    {
        int n,m;
        scan(n);
        scan(m);
        rep0(i,m)
        {
            int a,b;
            scan(a);
            scan(b);
            graph[a].push_back(b);
        }
        dfs(n);
        rep1(i,n)
        {
            v.push_back(make_pair(t[i],i));
        }
        sort(v.rbegin() , v.rend());

        rep0(i,v.size())
            cout<<v[i].second<<" ";

    }
    return 0;
}
