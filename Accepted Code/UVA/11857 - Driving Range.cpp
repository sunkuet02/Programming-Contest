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

int parent[1000100];
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
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int cnt =0;
    int highest;
    for(int i=0;i<(int)disk.size();i++)
    {
        int u = find_representative(disk[i].second.first);
        int v = find_representative(disk[i].second.second);

        if(u!=v)
        {
            parent[u] = v;
            cnt++;
            highest = disk[i].first;
            if(cnt ==n-1)
                return highest;
        }
    }
    return -1;
}
int main()
{
    int m,n;
   //freopen("input.txt","r",stdin);

    for(;;)
    {
        cin>>m>>n;
        if(m==0 && n==0)
            break;
        int s1,s2;
        int w;
        for(int i= 0 ;i<n;i++)
        {
            cin>>s1>>s2>>w;
            disk.push_back(make_pair(w,make_pair(s1,s2)));
        }

        int ret = dijkstra_pair(m);
        if(ret ==-1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ret<<endl;
        disk.clear();

    }
    return 0;
}

