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

int n, k, m ;
LL dp[55][55][55][3] ;

LL barCode(int pos , int bar, int con1, int current)
{
    if(con1 > m || bar> k )
        return 0 ;
    if(pos == n)
    {
        if(bar == k)
        {
            return 1;
        }
        else
            return 0 ;
    }

    LL & res = dp[pos][bar][con1][current] ;

    if(res!=-1) return res ;

    res = 0 ;
    if(current == 0)
    {
        res += barCode(pos + 1, bar, con1+1, 0) ;
        res += barCode(pos + 1, bar+1, 1, 1) ;
    }
    else
    {
        res += barCode(pos + 1, bar+1, 1,0);
        res += barCode(pos + 1, bar, con1+1,1) ;
    }

    return res ;
}

int main()
{
    int test ;
    while(scanf("%d %d %d",&n, &k , &m)!=EOF)
    {
        mem(dp, -1) ;

        LL res = barCode(1,1,1,1) ;
        printf("%lld\n",res) ;
    }
}

