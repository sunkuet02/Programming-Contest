#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>

using namespace std;
vector<int>node[500];
map<int,int>mp;
int bfs(int source,int ttl)
{
    queue<int>qu;
    qu.push(source);
    int taken[100]={0},distance[100];
    distance[source]=0;
    taken[source]=1;
    int reach=0;
    while(!qu.empty())
    {
        int u=qu.front();
        for(int i=0;i<node[u].size();i++)
        {
            int v=node[u][i];
            if(!taken[v])
            {
                distance[v]=distance[u]+1;
                if(distance[v]<=ttl) reach++;
                taken[v]=1;
                qu.push(v);
            }
        }
        qu.pop();
    }
    return reach;
}
int main()
{
    int i,j=0,m,node1,node2,notreach,reach,source,TTL;
    set<int>num_node;
    vector<int>v1,v2;
    set<int>::iterator it_set;
    while(1)
    {
        cin>>m;
        if(m==0) break;
        int a=1;
        for(i=1;i<=m;i++)
        {
            cin>>node1>>node2;
            v1.push_back(node1);
            v2.push_back(node2);
            num_node.insert(node1);
            num_node.insert(node2);
        }
        for(it_set=num_node.begin();it_set!=num_node.end();it_set++)
        {
            mp[*it_set]=(a++);
        }
        for(int i=0;i<m;i++)
        {
            node[mp.find(v1[i])->second].push_back(mp.find(v2[i])->second);
            node[mp.find(v2[i])->second].push_back(mp.find(v1[i])->second);
        }
        for(;;)
        {

            cin>>source>>TTL;
            if(source==0 && TTL==0 ) break;
            j++;
            int sourc=mp.find(source)->second;
            reach=bfs(sourc,TTL);
            notreach=num_node.size()-reach-1;
            cout<<"Case "<<j<<": "<<notreach<<" nodes not reachable from node "<<source<<" with TTL = "<<TTL<<"."<<endl;
        }
        mp.clear();
        num_node.clear();
        v1.clear();
        v2.clear();
        for(int i=0;i<=30;i++)
        {
            node[i].clear();
        }

    }
    return 0;
}

