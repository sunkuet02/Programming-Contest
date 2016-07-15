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
vector< pair< int, pair<int,int > > >disk;
vector<int>graph[205],cost[205];

class node
{

public:
    int u,w;
        node(int a,int b){u=a; w=b; }
};
int d[205];

int dijkstra(int n ,int source,int termination )
{

    memset(d,199000,n*sizeof(int ));

    queue<node>q;
    q.push(node(source,0));
    d[source]=2000000;
    while(!q.empty())
    {
        node top=q.front(); q.pop();
        int u=top.u;

        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(d[u]<cost[u][i])
                d[v] = d[u];
            else
                d[v] = cost[u][i];

            if(v==termination)
                return d[v];
            q.push(node(v,d[v]));

        }
    }
    return -1;
}



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
            graph[disk[i].second.first].push_back(disk[i].second.second);
            graph[disk[i].second.second].push_back(disk[i].second.first);
            cost[disk[i].second.second].push_back(disk[i].first);
            cost[disk[i].second.first].push_back(disk[i].first);

            parent[u] = v;
            cnt++;
            if(cnt == n-1)
                return cnt;
        }
    }
    return taken ;
}
int main()
{
    int m,n;
    //freopen("input.txt","r",stdin);
    int test = 0;
    map<string,int>mp;
    while(scanf("%d %d",&m,&n) && m && n)
    {

        mp.clear();
        disk.clear();
        for(int i = 0;i<200;i++)
        {
            cost[i].clear();
            graph[i].clear();

        }

        string s1,s2;
        int weight;
        int j = 1;
        for(int i = 1;i<=n;i++)
        {
            cin>>s1>>s2>>weight;
            if(!mp[s1])
                mp[s1] = j++;
            if(!mp[s2])
                mp[s2] = j++;
            disk.push_back(make_pair(weight,make_pair(mp.find(s1)->second,mp.find(s2)->second)));
        }

        cin>>s1>>s2;

        int ret = dijkstra_pair(m);

        int getvalue = dijkstra(m,mp.find(s1)->second,mp.find(s2)->second);
        printf("Scenario #%d\n",++test);
        cout<<getvalue<<" tons"<<endl<<endl;

    }
    return 0;
}

