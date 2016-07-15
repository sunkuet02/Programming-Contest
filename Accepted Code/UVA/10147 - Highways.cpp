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

int parent[100010];
vector< pair< double , pair<int,int > > >disk;

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
    int taken = 0;
    for(int i=0;i<(int)disk.size();i++)
    {
        int u = find_representative(disk[i].second.first);
        int v = find_representative(disk[i].second.second);

        if(u!=v)
        {
            if(disk[i].first >= 0.0)
            {
                cout<<disk[i].second.first<<" "<<disk[i].second.second<<endl;
                taken ++;
            }
            parent[u] = v;
            cnt++;
            if(cnt == n-1)
                return taken;
        }
    }
    return taken ;
}
int main()
{
    int m,n;
   //freopen("input.txt","r",stdin);
    vector< pair<int,int> >v;
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int num,num2;
        cin>>num;
        int a,b;
        for(int i = 1;i<=num;i++)
        {
            cin>>a>>b;
            for(int j =0;j<v.size();j++)
            {
                double dist = sqrt((double)((a-v[j].first)*(a-v[j].first) + (b-v[j].second)*(b-v[j].second)));
                disk.push_back(make_pair(dist,make_pair(j+1,i)));
            }
            v.push_back(make_pair(a,b));
        }

        cin>>num2;
        for(int i = 1;i<=num2;i++)
        {
            int a,b;
            cin>>a>>b;
            disk.push_back(make_pair(-10.0,make_pair(a,b)));
        }

        if( num ==1)
        {
            cout<<"No new highways need"<<endl;
            if(t!=test)
                cout<<endl;
            v.clear();
            disk.clear();
            continue;

        }
        int ret = dijkstra_pair(num);

        if(ret ==0)
        {
            cout<<"No new highways need"<<endl;
        }

        if(t!=test)
            cout<<endl;

        v.clear();
        disk.clear();
    }
    return 0;
}

