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
vector< pair< int , pair<int,int > > >disk,reserve;
vector<pair<int,int> >p_v;
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
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int cnt =0;
    int total =0;
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
    int N;
    int t=0;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&N)!=EOF)
    {
        if(t!=0)
            cout<<endl;
        t++;
        int x,y,w;
        for(int i=1;i<N;i++)
        {
            cin>>x>>y>>w;
            disk.push_back(make_pair(w,make_pair(x,y)));
        }
        int K;
        cin>>K;
        for(int i=0;i<K;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            reserve.push_back(make_pair(w,make_pair(x,y)));
        }
        int M;
        cin>>M;
        for(int i = 0;i<M;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            disk.push_back(make_pair(w,make_pair(x,y)));
        }
        int r1 = dijkstra_pair(N);
        for(int i=0;i<reserve.size();i++)
            disk.push_back(reserve[i]);
        int r2 = dijkstra_pair(N);
        cout<<r1<<endl<<r2<<endl;
        disk.clear();
        reserve.clear();
    }
    return 0;
}
