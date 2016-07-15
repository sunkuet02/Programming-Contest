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
vector<int>node[500];
vector<int>road;
int parent[100];
void bfs(int source, int termnt)
{
    for(int i=0; i<100; i++)
        parent[i] = i;
    queue<int>qu;
    qu.push(source);
    int taken[100]={0};
    taken[source ] =1;
    while(!qu.empty())
    {
        int u = qu.front();
        for(int i=0;i<node[u].size();i++)
        {
            int v = node[u][i];
            if(!taken[v])
            {
                parent[v]=u;
                taken[v]=1;
                if(v==termnt)
                {
                    while(!qu.empty())
                    {
                        qu.pop();
                    }
                    return;
                }
                qu.push(v);
            }
        }
        qu.pop();
    }
}
int find_road(int m)
{
    if(parent[m]==m)
    {
        road.push_back(m);
        return 0;
    }
    else
    {
        road.push_back(m);
        find_road(parent[m]);
    }
}
int main()
{
    int t;
    cin>>t;
    map<string,int>mp;
    vector<char>contain;
    for(int test=1;test<=t;test++)
    {
        int j=0;
        int route,want_result;
        cin>>route>>want_result;
        string s1,s2;
        for(int i=0;i<route;i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=j++;
                contain.push_back(s1[0]);
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=j++;
                contain.push_back(s2[0]);
            }
            node[mp.find(s1)->second].push_back(mp.find(s2)->second);
            node[mp.find(s2)->second].push_back(mp.find(s1)->second);
        }
        for(int i=0;i<want_result;i++)
        {
            cin>>s1>>s2;
            bfs(mp.find(s1)->second,mp.find(s2)->second);
            find_road(mp.find(s2)->second);
            reverse(road.begin(),road.end());
            for(int k=0;k<road.size();k++)
                cout<<contain[road[k]];
            cout<<endl;
            road.clear();
        }
        if(test!=t)
            cout<<endl;
        for(int i=0;i<100;i++)
            node[i].clear();
        contain.clear();
        mp.clear();
    }
    return 0;
}
