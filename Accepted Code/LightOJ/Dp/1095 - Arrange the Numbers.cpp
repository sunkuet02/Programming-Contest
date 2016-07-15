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

LL ncr[1005][1005];
LL fact[1005] ;
void factorial()
{
    fact[0]=1;
    rep1(i,1002)
    {
        fact[i] = fact[i-1] * (LL)(i);
        fact[i] %= mod;
    }
}
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





int main()
{

    NCR();
    factorial();

    int test;
    scan(test);
    rep1(t,test)
    {
        int n,m,k;
        scan(n);scan(m);scan(k);
        LL res = ncr[m][k];

        LL sum = fact[n-k];
        bool isminus = true;

        rep1(i,m-k)
        {
            if(isminus)
            {
                sum -= (ncr[m-k][i] * fact[n-k-i] )%mod;
                isminus = false;
            }
            else
            {
                sum += (ncr[m-k][i] * fact[n-k-i])%mod;
                isminus = true;
            }
            sum %= mod;
        }

        if(sum < 0)
        {
            sum *= (-1) ;
            sum %= mod;
            sum = mod - sum ;
        }
        res *= sum ;
        res %= mod;
        printf("Case %d: %lld\n",t,res);

    }
}

