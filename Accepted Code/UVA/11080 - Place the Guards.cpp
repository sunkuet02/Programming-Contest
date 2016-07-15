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
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mx 50005
#define sz 100005
#define mod 1000000007
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p) { T f = 1 ; for(int i=1 ; i<=p ; i++) f*=base; return f; }
template <typename T>  string NumberToString ( T Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}

int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

/*********************nCr**************************/
/*
int ncr[1005][1005];
int NCR()
{
    rep0(i,1003)
    {
        ncr[i][0] = 1;
    }
    rep1(i,1003)
    {
        rep1(j,1003)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %=mod;
        }
    }
}
*/

/****************************ExtendedEuclid&ModularInverse****/

pii extendedEuclid(int a,int b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
int modularInverse(int a,int m)
{
    pii ret = extendedEuclid(a,m);
    return ret.first % m ;
}
/****************************Implementation************************/



vector<int> graph[203] ;
bool visited[203],has[203] ;

int bicolor(int src)
{
    bool color[203];
    mem(color, false);

    queue<int> q;
    visited[src] = true;
    q.push(src);
    color[src] = true;
    int cnt1 = 1 , cnt0 = 0 ;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0 ; i< graph[u].size() ; i++ )
        {
            int v = graph[u][i];

            if(!visited[v])
            {
                visited[v] = true;

                q.push(v);
                if(color[u])
                {
                    color[v] = false;
                    cnt0 ++ ;
                }
                else
                {
                    color[v] = true;
                    cnt1 ++ ;
                }
            }
            else if(color[v] == color[u])
                return -1;
        }
    }
    return min(cnt0, cnt1) ;
}

int main()
{
    //READ();
    int test;
    scan(test) ;

    while(test--)
    {
        mem(visited, false);
        mem(has, false);
         int n,e;
         scan(n);scan(e);
         while(e--)
         {
             int a, b;
             scan(a);scan(b);
             graph[a].push_back(b);
             graph[b].push_back(a);
             has[a] = true;
             has[b] = true;
         }
         int total = 0 ;

         for(int i = 0 ; i< n  ; i ++ )
         {
			 if(!has[i]) {total ++ ; continue ; }
             if(visited[i] ) continue;
             int ret = bicolor(i);
             if(ret == -1)
             {
                 total = -1;
                 break;
             }
             total += ret;
         }
         cout << total << endl;

         rep0(i,n+2)
            graph[i].clear();
    }

}

