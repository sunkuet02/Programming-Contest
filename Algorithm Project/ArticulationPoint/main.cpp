   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL long long int
#define mx 15
#define MAX 15
#define sz 10005
using namespace std;

vector<int> graph[sz];
int low[sz], num[sz];
int counter ;
bool visited[sz],articp[sz];


int ArticulationPoint(int u, int p = -1)
{
    visited[u] = true;

    low[u] = num [u] = counter ++ ;
    int child = 0 ;

    for(int i = 0 ; i < graph[u].size() ; i++ )
    {
        int v = graph[u][i];

        if(v == p ) continue;

        if(!visited[v])
        {
            ArticulationPoint(v, u);

            low[u] = min(low[v], low[u]);

            /*
            if(low[v] > num[u]
            {
                cout << u << "-" << v << " is a bridge " << endl;
            }

            */
            if(low[v] >= num[u] && p!=-1)
            {
                articp[u] = true;
                //cout << u << " is a articulation point" << endl;
            }
            child ++ ;

        }
        else
        {
            low[u] = min(low[u], num[v]);
        }

    }
    if(p == -1 && child > 1)
    {
        articp[u] = true;
        //cout << u << " is a articulation point" << endl;
    }


}

int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        memset(visited, false, sizeof(visited));
        memset(articp, false, sizeof(articp));

        int m, n;
        scan(n); scan(m);

        while(m--)
        {
            int a, b;
            scan(a) , scan(b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        counter = 0;
        ArticulationPoint(1);

        int cnt = 0 ;
        rep1(i,n)
            cnt += articp[i];


        printf("Case %d: %d\n",t, cnt);

        rep0(i,n +3)
            graph[i].clear() ;
    }
}
