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
#define sz 1000002
#define mod 1000000007
#define MAX 10000005
using namespace std;

typedef pair<LL, LL> pii;


template<class T> inline T power(T base, int p)
{
    T f = 1 ;
    for(int i=1 ; i<=p ; i++) f*=base;
    return f;
}
template <typename T>  string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int setbit(int N,int pos)
{
    return N = N|(1<<pos);
}
int resetbit(int N, int pos)
{
    return N = N & ~(1<<pos) ;
}
bool checkbit(int N,int pos)
{
    return (bool) (N & 1<<pos) ;
}

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

vector<int>	graph[105] ;

void bfs(int src)
{
	queue<int> q ;
	q.push(src) ;
	int dis[105] = {1005} ;
	dis[0] = 0 ;
	int des = src;
	int maxi = 0 ;
	while(!q.empty())
	{
		int u = q.front() ;
		q.pop();

		for(int i = 0 ; i< graph[u].size() ; i++ )
		{
			int v = graph[u][i];

			if(dis[v] < dis[u] + 1 && dis[v]!=1005)
			{
				dis[v]= dis[u] + 1;
				q.push(v);
			}
			else if(dis[v] == 1005)
			{
				q.push(v);
				dis[v] = dis[u] + 1 ;
			}


			if(dis[v] > maxi)
			{
				maxi = dis[v];
				des = v;
			}
			else if(dis[v] == maxi )
			{
				if(v< des)
					des = v;
			}
		}
	}
	printf("The longest path from %d has length %d, finishing at %d.\n\n",src,maxi,des) ;
}

int main()
{
	//READ();
	int n;
	int test = 0 ;
	while(scan(n) && n)
	{
		int src ;
		scan(src) ;

		int a,b;
		while(1)
		{
			scan(a);
			scan(b);
			if(!a && !b) break;
			graph[a].push_back(b);
		}

		printf("Case %d: ", ++test);
		bfs(src) ;

		rep0(i,100+1)
			graph[i].clear();

	}
}

