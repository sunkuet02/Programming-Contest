/********solved*********/

#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

struct edge
{
    int u,v,w;
    bool operator <(const edge &p)const
    {
        return w<p.w;
    }
};

int parent[10050];
vector<edge>e;
int find_parent(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find_parent(parent[a]);
}
int MST(int n,int A)
{
    sort(e.begin(),e.end());
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int distance=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find_parent(e[i].u);
        int v=find_parent(e[i].v);
        if(u!=v && e[i].w<A)
        {
            parent[u]=v;
            distance+=e[i].w;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int a;
        a=find_parent(i);
        parent[i]=a;
    }
    return distance;
}
int main()
{
    int a;
    cin>>a;
    set<int>s;
    for(int k=1;k<=a;k++)
    {
        int n,m,A;
        cin>>n>>m>>A;
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
        int b=MST(n,A);
        for(int i=1;i<=n;i++)
            s.insert(parent[i]);
        int j=s.size();
        A=j*A+b;
        cout<<"Case #"<<k<<": "<<A<<" "<<j<<endl;
        e.clear();
        s.clear();
    }

    return 0;
}
