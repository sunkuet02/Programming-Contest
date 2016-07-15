#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <set>
#include <utility>

using namespace std;

int parent[1000];
vector< pair< int, pair<int,int > > >edge,mst_edges;

int find_representative(int m)
{
    if(parent[m]==m)
        return m;
    else
        return parent[m] = find_representative(parent[m]);
}
int first_mst(int n)
{
    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++)
        parent[i]=i;

    int cnt =0;
    int total = 0;
    for(int i=0;i<(int)edge.size();i++)
    {
        int u = find_representative(edge[i].second.first);
        int v = find_representative(edge[i].second.second);

        if(u!=v)
        {
            mst_edges.push_back(edge[i]);
            total +=edge[i].first;
            parent[u] = v;
            cnt++;
            if(cnt == n-1)
                return total;
        }
    }
    return total ;
}

int second_mst(int n,int m)
{

    for(int i=0;i<=n;i++)
        parent[i]=i;

    int cnt =0;
    int total = 0;
    for(int i=0;i<(int)edge.size();i++)
    {
        if(edge[i]==mst_edges[m])
            continue;
        int u = find_representative(edge[i].second.first);
        int v = find_representative(edge[i].second.second);

        if(u!=v)
        {
            total +=edge[i].first;
            parent[u] = v;
            cnt++;
            if(cnt == n-1)
                return total;
        }
    }
    return -1 ;
}

int main()
{
    int m,n;
    //freopen("input.txt","r",stdin);
    int test ;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++)
    {
        edge.clear();
        mst_edges.clear();

        scanf("%d %d",&m,&n);
        int u,v,weight;
        for(int i =0;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&weight);

            edge.push_back(make_pair(weight,make_pair(u,v)));
        }

        int ret = first_mst(m);
        int minimum = 300000000;
        for(int i =0;i<mst_edges.size();i++)
        {
            int second = second_mst(m,i);
            if(second<minimum && second !=-1)
                minimum = second;
        }


        cout<<ret<<" "<<minimum<<endl;

    }
    return 0;
}


