#include<iostream>
#include<set>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
using namespace std;
vector<int>v[500];

int bfs(int source,int ter)
{
    int distance[500];
    queue<int>q;
    int taken[500]= {0};
    q.push(source);
    taken[source]=1;
    distance[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<v[u].size(); i++)
        {
            int w=v[u][i];
            if(!taken[w])
            {
                distance[w]=distance[u]+1;
                taken[w]=1;
                q.push(w);
                if(w==ter) return distance[w];
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
    int m,l=0;

    cin>>m;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    string ar[600];
    map<string, int>mp;
    while(l!=m)
    {
        int M,N,P,n;
        string s1,s2;
        cin>>M>>N>>P;
        cout<<"DATA SET  "<<++l<<endl<<endl;;
        for(int i=1;i<=M;i++)
        {
            cin>>s1;
            mp[s1]=i;
        }
        while(N)
        {
            cin>>s1>>s2;
            v[mp.find(s1)->second].push_back(mp.find(s2)->second);
            v[mp.find(s2)->second].push_back(mp.find(s1)->second);
            N--;
        }
        while(P)
        {
            cin>>n>>s1>>s2;

            int total=bfs(mp.find(s1)->second,mp.find(s2)->second);
            P--;
            total=100*n*total;
            if(total!=0)
                cout<<"$"<<total<<endl;
            else cout<<"NO SHIPMENT POSSIBLE"<<endl;
        }
        cout<<endl;
        mp.clear();
        for(int i=0;i<500;i++)
        {
            v[i].clear();
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
