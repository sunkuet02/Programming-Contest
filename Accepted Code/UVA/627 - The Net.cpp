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
vector<int>v[500];
bool taken[5000];

int parent[500];
int bfs(int source , int temint)
{
    queue<int>q;
    while(!q.empty())
        q.pop();
    q.push(source);
    for(int i=0;i<=300;i++)
    {
        taken[i] = false;
        parent[i] = i;
    }
    taken[source] = true;

    while(!q.empty())
    {
        int u = q.front();
        for(int i=0;i<v[u].size();i++)
        {
            int m = v[u][i];
            if(!taken[m])
            {
                parent[m] = u;
                taken[m] = true;
                q.push(m);
            }
            if(m == temint)
                return 1;
        }
        q.pop();
    }
    return -1;
}
vector<int>path;
int find_path(int x)
{
    if(parent[x]==x)
    {
        cout<<x;
        for(int i=path.size()-1;i>=0;i--)
            cout<<" "<<path[i];
        cout<<endl;
        path.clear();
        return 0;
    }
    else
    {
        path.push_back(x);
        find_path(parent[x]);
    }
}
int main()
{
    string s;
    int m;
    int g=0;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&m)!=EOF)
    {
        g++;
        for(int t =0;t<m;t++)
        {
            cin>>s;
            int x=0;
            int i;
            for(i=0;s[i]!='-';i++)
            {
                x = x*10+(s[i]-48);
            }
            int m=0;
            for(i = i+1;i<s.size();i++)
            {
                if(s[i]==',')
                {
                    v[x].push_back(m);
                    m=0;
                }
                else
                    m = m*10+(s[i]-48);

            }
            if(m!=0)
            {
                v[x].push_back(m);
            }
        }
        int f;
        cout<<"-----"<<endl;
        cin>>f;
        for(int i=0;i<f;i++)
        {
            int a,b;
            cin>>a>>b;
            int ret = bfs(a,b);
            if(ret ==-1)
                cout<<"connection impossible"<<endl;
            else
                find_path(b);
        }
        for(int i=0;i<=300;i++)
            v[i].clear();

    }
    return 0;
}
