/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ freopen("input.txt","r",stdin);
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mxx 100005
#define sz 10005
#define mod 1000000007
#define MAX 1000005
#define inf INT_MAX
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
    return (bool) (N & (1<<pos ) ) ;
}
int noofsetbits(int N)
{
    return __builtin_popcount (N);
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

pii extendedEuclid(LL a,LL b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
LL modularInverse(LL a,LL m)
{
    pii ret = extendedEuclid(a,m);
    return ( (ret.first % m) + m ) %m ;
}
/*********************temp_Definition *************************/
/*
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


  // Knight Moves
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};
*/

/****************************Implementation************************/
int n , m;

LL cost[17][17] ;
int deg[18];
LL visited[1<<17];

void init()
{
    for(int i = 0 ; i<= 15; i++)
    {
        for(int j = 0 ; j<=15; j++ )
        {
            cost[i][j] = INT_MAX;
        }
    }

    mem(deg, 0);
    mem(visited, -1);
}
void floyedWarshal()
{
    rep(k,1,n)
    {
        rep(i,1,n)
        {
            rep(j,1,n)
            {
                if(cost[i][k] != INT_MAX &&  cost[k][j] != INT_MAX)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

LL cal(int mask)
{
    //cout << mask << endl;
    if(!mask) return 0;
    int temp ;
    if(visited[mask]>=0)  return visited[mask];
   // cout << "s" << endl;
    LL ans = INT_MAX;

    for(int i = 1 ; i<=  n;  i++ )
    {
        for(int j = i+1; j<= n ; j++ )
        {
            if(checkbit(mask,i) && checkbit(mask, j))
            {
                temp = mask;
                temp = resetbit(temp, i);
                temp = resetbit(temp, j);
                ans = min( ans, cal(temp)+ cost[i][j]);

            }
        }
    }
    return visited[mask] = ans;
}

int main()
{

    READ;
    int test;
    sc(test);
    rep(t,1,test)
    {
        init();

        LL total = 0 ;
        sc(n);sc(m);
        rep(tt,1,m)
        {
            int x, y;
            LL w;
            sc(x);sc(y);scanf("%lld",&w);
            total += w;

            cost[x][y] = min(cost[x][y], w);
            cost[y][x] = cost[x][y];
            deg[x]++ ; deg[y] ++ ;
        }

        floyedWarshal();

        int mask = 0 ;
        //cout << cost[1][3] << endl;
        rep(i,1,n)
        {
            //cout << mask << ends << i << endl ;
            if(deg[i]%2==1)
                mask = setbit(mask, i);
        }

        total += cal(mask);

        printf("Case %d: %lld\n",t, total);

    }
}

