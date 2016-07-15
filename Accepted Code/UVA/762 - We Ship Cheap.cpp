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

vector<int>node[1000];
map<string , int > mp;
vector<int>rasta;
int parent[50000];
int bfs(int source,int termint)
{
    for(int i=0; i<10000; i++)
        parent[i] = i;
    queue<int>qu;
    qu.push(source);
    int taken[10000]= {0};
    taken[source]=1;
    int reach=0;
    while(!qu.empty())
    {
        int u=qu.front();
        for(int i=0; i<node[u].size(); i++)
        {
            int v=node[u][i];
            if(!taken[v])
            {
                parent[v]=u;
                taken[v]=1;
                if(v ==termint)
                {
                    while(!qu.empty())
                        qu.pop();
                    return 1;
                }
                qu.push(v);

            }
        }
        qu.pop();
    }
    return -1;
}


int find_route(int m)
{
    if(parent[m]==m)
    {
        rasta.push_back(m);
        return 0;
    }
    else
    {
        rasta.push_back(m);
        find_route(parent[m]);
    }
}
int main()
{

    int a;
    string s1,s2;
    vector<string>road_name;
    int aa=0;

    while(scanf("%d",&a)!=EOF)
    {
        if(aa!=0)
            cout<<endl;
        aa++;
        int j=1;
        for(int i=0; i<a; i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=j++;
                road_name.push_back(s1);
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=j++;
                road_name.push_back(s2);
            }
            node[mp.find(s1)->second].push_back(mp.find(s2)->second);
            node[mp.find(s2)->second].push_back(mp.find(s1)->second);
        }
        cin>>s1>>s2;
        if(mp.find(s1)==mp.end())
        {
            mp[s1]=j++;
            road_name.push_back(s1);
        }
        if(mp.find(s2)==mp.end())
        {
            mp[s2]=j++;
            road_name.push_back(s2);
        }
        int val = bfs(mp.find(s1)->second,mp.find(s2)->second);

        if(val == -1)
            cout<<"No route"<<endl;
        else
        {
            find_route(mp.find(s2)->second);
            reverse(rasta.begin(),rasta.end());
            for(int i=0; i<rasta.size()-1; i++)
                cout<<road_name[rasta[i]-1]<<" "<<road_name[rasta[i+1]-1]<<endl;
        }
        rasta.clear();
        road_name.clear();
        mp.clear();
        for(int i=0; i<1000; i++)
            node[i].clear();
    }
    return 0;
}
