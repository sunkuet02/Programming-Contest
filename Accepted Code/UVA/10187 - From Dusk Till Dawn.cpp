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

int bfs(int source,int termnt)
{
    queue<int>qu;
    qu.push(source);
    int taken[100]={0},distance[100];
    distance[source]=0;
    taken[source]=1;
    while(!qu.empty())
    {
        int u=qu.front();
        for(int i=0;i<node[u].size();i++)
        {
            int v=node[u][i];
            if(!taken[v])
            {
                distance[v]=distance[u]+1;
                taken[v]=1;
                if(v == termnt)
                {
                    while(!qu.empty())
                        qu.pop();
                    return distance[v];
                }
                qu.push(v);
            }
        }
        qu.pop();
    }
    return -1;
}
int main()
{
    int t;
    freopen("input.txt","r",stdin);
    cin>>t;
    map<string,int>mp;
    for(int test=1;test<=t;test++)
    {
        int route;
        cin>>route;
        string s1,s2;
        int j=1;
        int start_time,travel_time;
        for(int r=1;r<=route;r++)
        {
            cin>>s1>>s2>>start_time>>travel_time;
            if(mp.find(s1)==mp.end())
                mp[s1]=j++;
            if(mp.find(s2)==mp.end())
                mp[s2]=j++;
            if(start_time>=18 && (start_time+travel_time)<=30)
            {
                node[mp.find(s1)->second].push_back(mp.find(s2)->second);
                node[mp.find(s2)->second].push_back(mp.find(s1)->second);
            }
        }
        for(int k=1;k<j;k++){
                cout<<k<<ends;
            for(int i=0;i<node[k].size();i++)
                cout<<node[k][i]<<ends;
                cout<<endl;
        }
        cin>>s1>>s2;
        int result = bfs(mp.find(s1)->second,mp.find(s2)->second);
        cout<<"Test Case "<<test<<"."<<endl;
        if (result==-1)
            cout<<"There is no route Vladimir can take."<<endl;
        else
            cout<<"Vladimir needs "<<result<<" litre(s) of blood."<<endl;
        mp.clear();
        for(int i=0;i<101;i++)
            node[i].clear();

    }
    return 0;
}
