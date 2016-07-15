/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define Read freopen("input.txt","r",stdin);
#define Write freopen("output.txt","w",stdout);
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

char grid[105][105] ;
int r, c;
LL dp[105][105] ;

int main()
{
    //Read;
    int test;
    sc(test);

    rep(t,1,test)
    {
        if(t>1)
            printf("\n");
        sc(r);sc(c);

        for(int i = 0 ; i <=r ; i++ )
        {
            for(int j = 0  ; j<=c; j++ )
                grid[i][j] = '.';
        }
        getchar();

        for(int j = 0 ; j< r ;j++ )
        {
            string s;
            getline(cin,s);

            int i = 0 ;
            int x = 0 ;
            while(s[i]!='\n' && s[i]!=' ' && i< s.size())
            {
                x = x*10 ;
                x +=  (s[i] - 48) ;
                //cout << x << ends << s[i] << endl;
                i++ ;
            }
            //cout << x << endl;

            int y = 0 ;

            while(s[i]!='\n' && i<s.size())
            {
                if(s[i]==' ')
                {
                    grid[x][y] = '#';
                    y = 0;
                    i++;
                    continue;
                }

                y = y*10 + s[i] - 48 ;
                i++;
            }
            if(y != 0)
            {
                grid[x][y] = '#';
                    y = 0;
            }
        }

        mem(dp, 0);
        dp[1][1] = 1 ;

        for(int i = 1; i<= r; i++ )
        {
            for(int j = 1; j<= c; j++ )
            {
                if(i==1 && j==1) continue;
                if(grid[i][j] !='#')
                {
                    dp[i][j] = dp[i-1][j] +dp[i][j-1] ;
                    //cout << dp[i][j] << ends;
                }
            }
            //cout << endl;
        }
        if(grid[1][1]=='#' || grid[r][c]=='#')
            dp[r][c] = 0;
        printf("%d\n",dp[r][c]);

    }


}


