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

int main()
{
    vector<int>order[105];
    vector<int>v,now;
    int indegree[105];
    int visited[105];
    int m,n;
    for(;;)
    {
        cin>>m>>n;
        if(m==0 && n==0)
            break;
        for(int i=0;i<=m;i++)
        {
            indegree[i] = 0;
            visited[i] =0;
        }
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            order[x].push_back(y);
            indegree[y]++;
        }
        while(v.size()!=m)
        {
            for(int i=1;i<=m;i++)
            {
                if(indegree[i]==0 && !visited[i])
                {
                    v.push_back(i);
                    now.push_back(i);
                    visited[i]=1;
                }

            }
            for(int k=0;k<now.size();k++)
            {
                for(int j=0;j<order[now[k]].size();j++)
                    {
                        int temp = order[now[k]][j];
                        indegree[temp]--;
                    }
            }
            now.clear();
        }
        cout<<v[0];
        for(int i=1;i<v.size();i++)
            cout<<" "<<v[i];
        cout<<endl;
        for(int i=0;i<100;i++)
            order[i].clear();
        v.clear();
    }
    return 0;
}
