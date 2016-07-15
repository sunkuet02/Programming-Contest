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

int parent[200005];
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
    sort(disk.begin(),disk.end());
    for(int i=0;i<n;i++)
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
            total +=disk[i].first;
            if(cnt ==n-1) break;
        }
    }
    return total;
}
int main()
{
    int m,n;
    for(;;)
    {
        cin>>n>>m;
        if(m == 0 && n == 0 )
            break;
        int total = 0;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            total += w;
            disk.push_back(make_pair(w,make_pair(u,v)));
        }
        int r = dijkstra_pair(n);
        cout<<total - r<<endl;
        disk.clear();
    }
    return 0;
}
