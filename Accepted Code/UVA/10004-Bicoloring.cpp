//Accepted
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<list>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<fstream>
#include<clocale>
#include<ctime>
#include<cctype>
using namespace std;
vector<int>graph[200];
void bfs(int source)
{
    int count=0;
    queue<int>q;
    int taken[200]={0};
    q.push(source);
    taken[source]=1;
    int search[200];
    search[source]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(!taken[v])
            {
                if(search[u]==1)
                    search[v]=0;
                else
                    search[v]=1;
                taken[v]=1;
                q.push(v);
            }
            else
            {
                if(search[u]==search[v])
                {
                    count=1;
                    break;
                }
            }

        }
        if(count==1) break;
        q.pop();
    }
    if(count==1) cout<<"NOT BICOLORABLE."<<endl;
    else cout<<"BICOLORABLE."<<endl;
    while(!q.empty()) q.pop();
}
int main()
{
    int num1,num2,n,l;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        cin>>l;
        for(int i=1;i<=l;i++)
        {
            cin>>num1>>num2;
            graph[num1].push_back(num2);
            graph[num2].push_back(num1);
        }
        bfs(num1);
        for(int i=0;i<200;i++)
            graph[i].clear();
    }
    return 0;
}

