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
vector<int>giovanni[500000];
void bfs(int m)
{
     queue<int>q;
     int distance[m+1];
     bool istaken[m+1];
     memset(distance,0,sizeof(distance));
     memset(istaken,false,sizeof(istaken));
     istaken[0] = true;
     q.push(0);
     while(!q.empty())
     {
         int u = q.front();
         for(int i = 0;i<giovanni[u].size();i++)
         {
             int v = giovanni[u][i];
             if(!istaken[v])
             {
                 distance[v] = distance[u] +1;
                 istaken[v] = true;
                 q.push(v);
             }
         }
         q.pop();
     }
     for(int i =1;i<m;i++)
        cout<<distance[i]<<endl;
     return;
}
int main()
{
    int te;
    //freopen("input.txt","r",stdin);
    cin>>te;
    for(int t=1;t<=te;t++)
    {
        int m,n;
        cin>>m>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            giovanni[x].push_back(y);
            giovanni[y].push_back(x);
        }
        bfs(m);
        for(int i=0;i<=m*(m-1)/2;i++)
            giovanni[i].clear();
        if(t!=te)
            cout<<endl;
    }

    return 0;
}
