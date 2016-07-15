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
int MST(int m)
{
    sort(e.begin(),e.end());
    for(int i=1;i<=m;i++)
        parent[i]=i;
    int countt=0,distance=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find_parent(e[i].u);
        int v=find_parent(e[i].v);
        //cout<<u<<ends<<v<<endl;
        if(u!=v)
        {
            parent[u]=v;
            countt++;
            distance+=e[i].w;
            if(countt==m-1) break;
        }
    }
    //for(int i=1;i<=5;i++) cout<<parent[i]<<ends;                 //check parent
    return distance;
}
int main()
{
    int m,ed;
    cin>>m>>ed;
    for(int i=1;i<=ed;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    cout<<MST(m);

    return 0;
}
