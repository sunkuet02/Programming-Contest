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

int parent[5000];
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
    for(int i=1; i<=n; i++)
        parent[i]=i;
    int cnt =0, total =0;
    for(int i=0; i<(int)disk.size(); i++)
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

    map<string, int>mp;
    int test;
    cin>>test;
    for(int te =1;te<=test;te++)
    {
        cin>>n>>m;
        int j =1;
        for(int i=0; i<m; i++)
        {
            int w;
            string s1,s2;
            cin>>s1>>s2>>w;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=j++;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=j++;
            }
            disk.push_back(make_pair(w,make_pair(mp.find(s1)->second,mp.find(s2)->second)));
        }
        int r = dijkstra_pair(n);
        cout<<r<<endl;
        if(te!=test)
            cout<<endl;
        mp.clear();
        disk.clear();
    }
    return 0;
}
