   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin)
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mx 205
#define sz 100005
#define mod 1000000007
using namespace std;

typedef pair<LL, LL> pii;

vector<int> intToBinary(int n){vector<int> s;  while(n) { s.push_back(n%2);n/=2;} if(s.size()==0) s.push_back(0);reverse(s.begin(), s.end()); return s;}
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

/**************************Implementation*****************************/

int surcharge[15][15] ;
int dp[1<<14 + 5] ;
int n;

int minRide(int mask)
{
    if(mask == (1<<n) -1 ) return 0 ;
    int & ret = dp[mask] ;
    if(ret!=-1) return ret ;

    ret = 1<<30 ;
    for(int i = 0 ; i< n ;i++ )
    {
        if(!checkbit(mask,i))
        {
            int val = surcharge[i][i];
            for(int j = 0 ; j< n ;j++ )
            {
                if(checkbit(mask,j) && j!=i)
                {
                    val += surcharge[i][j] ;
                }
            }
            int p = val + minRide(setbit(mask, i));
            ret = min(ret, p);
        }
    }
    return ret  ;
}

int main()
{


    int test;
    scan(test);
    rep1(t,test)
    {
       mem(dp,-1);

       scan(n);
       rep0(i,n)
       {
           rep0(j,n)
           {
               scan(surcharge[i][j]);
           }
       }
       int ret = minRide(0);

       printf("Case %d: %d\n",t,ret);

    }
}
