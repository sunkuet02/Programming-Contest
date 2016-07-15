#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge
{
    int u,v,w;
    bool operator <(const edge &p)const
    {
        return w<p.w;
    }
};

int parent[100];
vector<edge>e;
int find_parent(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find_parent(parent[a]);
}
int MST()
{
    sort(e.begin(),e.end());
    for(int i=1;i<=5;i++)
        parent[i]=i;
    int countt=0,distance=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find_parent(e[i].u);
        int v=find_parent(e[i].v);
        if(u!=v)
        {
            cout<<"sss ";
            parent[u]=v;
            countt++;
            distance+=e[i].w;
            if(countt==e.size()-1) break;
        }
    }
    return distance;
}
int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    cout<<MST();

    return 0;
}
