#include<bits/stdc++.h>
#define m 1005
#define Max 1000005
#define scan(a) scanf("%d",&a)
using namespace std;

vector<int>graph[Max],cost[Max];
struct node
{
    int u,w;
    node(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const node & p)const
    {
        return w>p.w;
    }
};

int d[Max];

int dijkstra(int a)
{
    priority_queue < node > q;
    memset(d,1000000 , sizeof(d));
    q.push(node(0,a));
    d[0]=a;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;



        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];

            if(d[v]>d[u]+cost[u][i])
            {
                d[v]=d[u]+cost[u][i];
                q.push(node(v,d[v]));
            }
        }

    }
    return -1;
}

int con[m*m];

int main()
{
    int M,N;
    int te;
    //freopen("input.txt","r",stdin);
    scan(te);

    for(int t = 1; t<= te; t++ )
    {


        scan(N);
        scan(M);
        for(int i = 0 ; i<M*N+2; i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
        for(int i = 0 ; i< N ; i++ )
        {
            for(int j = 0 ; j< M ;j++ )
            {
                int a;
                scan(con[i*M+j]);

            }
        }

        for(int i = 0 ; i< N ; i++ )
        {
            for(int j = 0 ; j< M ;j++ )
            {
                if(j!=0 )
                {
                    graph[i*M+j-1].push_back(i*M+j);
                    cost[i*M+j-1].push_back(con[i*M+j]);
                }
                if(j!=M-1 && i*M+j != 0)
                {
                    graph[i*M+j+1].push_back(i*M+j);
                    cost[i*M+j+1].push_back(con[i*M+j]);
                }
                if(i!=0 )
                {
                    graph[(i-1)*M+j].push_back(i*M+j);
                    cost[(i-1)*M+j].push_back(con[i*M+j]);
                }
                if(i!=N-1 && i*M+j != 0)
                {
                    graph[(i+1)*M+j].push_back(i*M+j);
                    cost[(i+1)*M+j].push_back(con[i*M+j]);
                }

            }
        }
//        for(int i = 0 ; i< N*M;  i ++ )
//        {
//            cout<<i<<"   ";
//            for(int j = 0 ; j<graph[i].size() ; j++)
//                cout<<graph[i][j]<<ends;
//            cout<<endl;
//        }
         dijkstra(con[0]);
         int ret = d[N*M-1];
        cout<<ret<<endl;


    }
}

