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
vector<int>graph[30];

int BFS(int start,int termint)
{
    queue<int >q;
    int distance[30];
    bool istaken[30] = {false};
    istaken[start ] = true;
    distance[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i<(int)graph[u].size();i++)
        {
            int v  = graph[u][i];
            if(!istaken[v])
            {
                distance[v] = distance[u] + 1;
                istaken[v]  = true;
                if(v == termint)
                {
                    while(!q.empty())
                        q.pop();
                    return distance[v];
                }

                q.push(v);

            }
        }
    }
}
int main()
{
    int I,J,t=0;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&I)!=EOF)
    {

        t++;

        for(int i = 0;i<I;i++)
        {
            cin>>J;
            graph[1].push_back(J);
            graph[J].push_back(1);
        }
        for(int j = 2;j<=19;j++)
        {
            cin>>I;
            for(int i = 0;i<I;i++)
            {
                cin>>J;
                graph[j].push_back(J);
                graph[J].push_back(j);
            }
        }
        int N;
        cin>>N;
        printf("Test Set #%d\n",t);
        for(int n = 1;n<=N;n++)
        {
            int p,q;
            cin>>p>>q;
            int ret  = BFS(p,q);
            printf("%2d to %2d: %d\n",p,q,ret);
        }

        for(int i = 0;i<=20;i++)
            graph[i].clear();
        cout<<endl;
    }

    return 0;
}
