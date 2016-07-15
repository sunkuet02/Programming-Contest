#include <bits/stdc++.h>

using namespace std;

vector<pair < pair <int , int > , int > >graph;

void BellmanFord(int nodeNumber , int source )
{
    int dis[2005] ;
    for(int i = 0 ; i < nodeNumber + 1 ; i++ )
        dis[i] = 2000005 ;

    dis[source] = 0 ;

    for(int i = 0 ; i<nodeNumber ; i++ )
    {
        for(int i = 0 ; i< graph.size() ; i++ )
        {
            if(dis[graph[i].first.second]>dis[graph[i].first.first] + graph[i].second)
                dis[graph[i].first.second] = dis[graph[i].first.first] + graph[i].second ;
        }

    }


    for(int i = 0 ; i<nodeNumber ; i++ )
    {
        for(int i = 0 ; i< graph.size() ; i++ )
        {
            if(dis[graph[i].first.second]>dis[graph[i].first.first] + graph[i].second)
            {
                cout<< "possible" <<endl ;

                return ;
            }
        }

    }
   cout<<"not possible"<<endl;
   return ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        graph.clear();
        int nodeNumber, edgeNumber ;
        cin>>nodeNumber >> edgeNumber ;
        graph.clear();
        int u , v , w;
        for(int i = 0 ; i < edgeNumber ; i++ )
        {
            cin>>u >> v>> w;
            graph.push_back(make_pair(make_pair(u,v), w));
        }

        BellmanFord(nodeNumber , v );
    }

    return 0;
}

