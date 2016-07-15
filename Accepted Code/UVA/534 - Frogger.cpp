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
vector< pair< double, pair<int,int > > >disk;
vector<int>graph[205];
vector<double>cost[205];

class node
{

public:
    int u;
    double w;
        node(int a,double b){u=a; w=b; }
};
double d[205];
bool istaken[205];
double dijkstra(int n  )
{

    memset(d,199000.0,n*sizeof(int ));
    memset(istaken,false,sizeof(istaken));

    queue<node>q;
    q.push(node(1,0.0));
    d[1]=0.0;

    while(!q.empty())
    {
        node top=q.front(); q.pop();
        int u=top.u;

        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(d[u]>cost[u][i])
                d[v] = d[u];
            else
                d[v] = cost[u][i];

            if(v==2)
                return d[v];
            if(!istaken[v])
                q.push(node(v,d[v]));
            istaken[v] = true;

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
    int m,n,p;
    //freopen("input.txt","r",stdin);
    int test = 0;
    vector<pair<int,int> >v;
    while(scanf("%d",&n) && n  )
    {
        disk.clear();
        v.clear();
        for(int i = 0;i<200;i++)
        {
            cost[i].clear();
            graph[i].clear();

        }
//        if(test!=0)
//            cout<<endl;
        int s1,s2;
        int weight;
        int j = 1;

        for(int i = 1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            for(int j =0;j<i-1;j++)
            {

                double dist = sqrt((double)((a-v[j].first)*(a-v[j].first) + (b-v[j].second)*(b-v[j].second)));
               // cout<<i<<ends<<j+1<<ends<<dist<<endl;

                disk.push_back(make_pair(dist,make_pair(i,j+1)));
            }
            v.push_back(make_pair(a,b));
        }
        int ret = dijkstra_pair(n);

        double getvalue = dijkstra(n);

        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++test,getvalue);


    }
    return 0;
}


