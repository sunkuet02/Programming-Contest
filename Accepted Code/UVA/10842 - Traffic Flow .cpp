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

int parent[500];
vector< pair< int , pair<int,int > > >disk;
int find_representative(int m)
{
    if(parent[m]==m)
        return m;
    else
        return parent[m] = find_representative(parent[m]);
}
int dijkstra_pair(int n)
{
    sort(disk.rbegin(),disk.rend());
    int min = disk[0].first;
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int cnt =0, total =0;
    for(int i=0;i<(int)disk.size();i++)
    {
        int u = find_representative(disk[i].second.first);
        int v = find_representative(disk[i].second.second);

        if(u!=v)
        {
            parent[u] = v;
            cnt++;
            if(min>disk[i].first)
                min = disk[i].first;
            if(cnt ==n-1)
                break;
        }
    }
    return min;
}
int main()
{
    int t;
    cin>>t;
    for(int test = 1;test<=t;test++)
    {
        int m,n;
        cin>>m>>n;
        for(int i=0;i<n;i++)
        {
            int u, v,w;

            cin>>u>>v>>w;
            disk.push_back(make_pair(w,make_pair(u,v)));
        }
        int ret = dijkstra_pair(m);
        cout<<"Case #"<<test<<": "<<ret<<endl;
        disk.clear();
    }
    return 0;
}
