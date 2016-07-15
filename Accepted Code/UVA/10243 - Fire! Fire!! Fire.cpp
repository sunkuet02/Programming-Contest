#include<bits/stdc++.h>
#define Max 1005
using namespace std;

int dp[Max][10] ;
vector<int>edge[Max] ;
int parent[Max] ;

int minVertexCover(int u , int isguard)
{
    if(edge[u].size() == 0 ) return 1 ;

    if(dp[u][isguard]!=-1) return dp[u][isguard] ;

    int sum = 0 ;
    for(int  i = 0 ; i<edge[u].size()  ; i++ )
    {
        int v = edge[u][i] ;
        if(v!= parent[u])
        {
            parent[v]= u ;
            if(isguard==0)  sum+= minVertexCover(v,1);
            else
                sum+=min(minVertexCover(v,1) , minVertexCover(v,0));
        }
    }
    return dp[u][isguard] = sum + isguard;
}

int main()
{
    //freopen("input.txt", "r"  , stdin);

    while(1)
    {
        memset(dp, -1 , sizeof(dp));
        int n;
        cin>> n ;

        if(n==0)
            break;

        for(int i = 1 ; i<=  n;  i ++ )
        {
            int a;
            cin>>a ;
            for(int  j  = 1 ; j<=a ; j++ )
            {
                int b;
                cin>>b;
                edge[i].push_back(b);
            }
        }
        for(int i = 0 ; i<= n ; i++ )
            parent[i] =  i ;

        int ret =min( minVertexCover(1,0) , minVertexCover(1,1) );
        cout<<ret<<endl;

        for(int i = 0 ; i<= n+1 ; i++ )
            edge[i].clear();
    }

    return 0;
}

