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
using namespace std;

vector< pair<int,pair<int,int> > >disk;
vector<int>reserve;
int parent[5000];
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
    for(int i=0; i<=n; i++)
        parent[i]=i;
    int cnt =0, total =0;
    int i;
    for( i=0; i<(int)disk.size(); i++)
    {
        int u = find_representative(disk[i].second.first);
        int v = find_representative(disk[i].second.second);
        if(u!=v)
        {
            parent[u] = v;
            cnt++;
            if(cnt ==n-1) break;
        }
        else{
            reserve.push_back(disk[i].first);
        }
    }
    if(i!=disk.size())
        for(i=i+1;i<disk.size();i++)
            reserve.push_back(disk[i].first);
    return 0;
}
int main()
{
    int m,n;

    for(;;)
    {
        cin>>m>>n;
        if(m==0 && n==0)
            break;
        for(int i=0;i<n;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            disk.push_back(make_pair(w,make_pair(u,v)));
        }
        dijkstra_pair(m);
        if(reserve.size()==0)
            cout<<"forest"<<endl;
        else
        {
            sort(reserve.begin(),reserve.end());
            cout<<reserve[0];
            for(int i =1;i<reserve.size();i++)
                cout<<" "<<reserve[i];
            cout<<endl;
        }
        disk.clear();
        reserve.clear();
    }
    return 0;
}
