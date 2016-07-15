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
vector< pair< float , pair<int,int > > >disk;
vector<pair<float,float> >p_v;
int find_representative(int m)
{
    if(parent[m]==m)
        return m;
    else
        return parent[m] = find_representative(parent[m]);
}
float dijkstra_pair(int n)
{
    sort(disk.begin(),disk.end());
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int cnt =0;
    float total =0;
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
    int t;
    cin>>t;
    for(int test =1;test<=t;test++)
    {
        cin>>m;
        float x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            for(int j=0;j<p_v.size();j++)
            {
                float cost =(float) sqrt((float)(abs(p_v[j].first-x)*abs(p_v[j].first-x))+(float)(abs(p_v[j].second-y)*abs(p_v[j].second-y)));
                disk.push_back(make_pair(cost,make_pair(i,j)));

            }
            p_v.push_back(make_pair(x,y));
        }
        float r = dijkstra_pair(m);
        printf("%.2f\n",r);
        if(test!=t)
            cout<<endl;
        p_v.clear();
        disk.clear();
    }
    return 0;
}
