#include<bits/stdc++.h>
#define N 2505

using namespace std;

vector<int>graph[N] ;
int result[N] ;

int BFS(int noOfNode , int source )
{
    int distance[N] ;
    bool visited[N]  ;

    memset(visited , false  , sizeof(visited)) ;
    memset(result , 0 , sizeof(result));

    distance[source] = 0 ;

    queue<int> q;

    q.push(source);
    visited[source] = true;
    if(graph[source].size() == 0)
        return -1 ;

    while(!q.empty())
    {
        int u = q.front() ;
        q.pop() ;

        for(int i = 0 ; i<(int) graph[u].size() ; i++ )
        {
            int v = graph[u][i] ;
            if(!visited[v])
            {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                result[distance[v]] ++ ;
                q.push(v);
            }
        }
    }

    return 0 ;

}

int main()
{
    //freopen("input.txt" , "r" , stdin) ;

    int noOfNode ,  source , destination ;
    cin>>noOfNode ;
    for(int i = 0 ; i< noOfNode ; i++)
    {
        int a;
        cin>>a;
        for(int j = 0 ; j< a; j++ )
        {
            int u ;
            cin>> u;
            graph[i].push_back(u) ;

        }
    }

    int T;
    cin>> T ;

    for(int i = 0 ; i< T ; i++ )
    {
        cin>> source ;

        int distance = BFS(noOfNode , source) ;
        if(distance !=0 )
            cout<<0<<endl;
        else
        {
            int bloomDay , bloomSize = 0;
            for(int j = 1 ; j< noOfNode ; j ++ )
            {
                if(result[j]>bloomSize)
                {
                    bloomDay = j;
                    bloomSize = result[j] ;
                }
            }

            cout<<bloomSize <<" "<< bloomDay <<endl;
        }
    }


    return 0;
}

