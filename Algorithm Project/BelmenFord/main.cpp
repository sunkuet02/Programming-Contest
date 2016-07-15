   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  Codeforces: sun.  , Topcoder : sun.
   *  Uva: sun. , SPOJ : sun_kuet  , LOJ : 5002
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
#define mx 205
#define INF 1600050
using namespace std;

vector< pair< pair <int, int > , int > > edge;
int dis[mx],arr[mx];
int n;

void bellmanFord()
{
    rep0(i,n+2)  dis[i] = INF;
    dis[1] = 0;
    rep1(i,n-1)
    {
        rep0(j,edge.size())
        {
            if(dis[edge[j].first.first]!=INF)
                if(dis[edge[j].first.first] + edge[j].second < dis[edge[j].first.second])
                {
                    dis[edge[j].first.second] = dis[edge[j].first.first] + edge[j].second;
                }
        }
    }
    rep0(j,edge.size())
        {
            if(dis[edge[j].first.first]!=INF)
                if(dis[edge[j].first.first] + edge[j].second < dis[edge[j].first.second])
                {
                    dis[edge[j].first.second] = INF;
                }
        }
}

int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        scan(n);
        rep1(i, n) scan(arr[i]);

        int m;
        scan(m);
        rep1(i,m)
        {
            int u,v;
            scanf("%d %d",&u, &v);

            int value = arr[v] - arr[u];
            value = value * value * value;
            edge.push_back(make_pair(make_pair(u,v),value));
        }

        bellmanFord();

        scan(m);
        printf("Case %d:\n",t);
        rep1(i,m)
        {
            int a;
            scan(a);
            if(dis[a]<3 || dis[a]==INF)
            {
                printf("?\n");
            }
            else
            {
                printf("%d\n",dis[a]);
            }
        }
        edge.clear();
    }
}
