/************Accepted**********/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>

using namespace std;

vector<int>claw[305];
void clawDecomposition(int a)
{
    queue<int>q;
    q.push(a);
    int Finder =0;
    int taken[300]={0};
    taken[a]=1;
    int pathColor[300];
    pathColor[a]=1;

    while(!q.empty())
    {
        int u = q.front();
        for(int i=0;i<claw[u].size();i++)
        {
            int v = claw[u][i];
            if(!taken[v])
            {
                if(pathColor[u]==1)
                    pathColor[v]=0;
                else
                    pathColor[v]=1;
                taken[v]=1;
                q.push(v);
            }
            else
            {
                if(pathColor[u]==pathColor[v])
                {

                    Finder = 1;
                    break;
                }
            }
        }
        if(Finder ==1)
            break;
        q.pop();
    }
    if(Finder ==1) cout<<"NO"<<endl;
    else if(Finder ==0) cout<<"YES"<<endl;
    while(!q.empty()) q.pop();
}
int main()
{
    int V;

    while(scanf("%d",&V) && V)
    {
        int a,b,c;
        while(1)
        {
            cin>>a>>b;
            if(a!=0) c=a;
            if(a==0 && b==0)
                break;
            claw[a].push_back(b);
            claw[b].push_back(a);
        }
        clawDecomposition(c);
        for(int i=0;i<=V;i++)
            claw[i].clear();
    }
    return 0;
}
