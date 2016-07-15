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

vector<int> v;
LL dp[205][25][12][21];
int n;
LL Sums(int pos, int modValue, int rem,int d)
{
    if (!modValue && !rem) return 1;
    else if(pos>= n || rem <=0) return 0 ;

    LL & res = dp[pos][modValue][rem][d];
    if(res!=-1) return res;

    res = 0;
    LL val = modValue + v[pos];
    if(val < 0)
    {
        val *= (-1) ;
        val %= d;
        val = d - val;
    }
    res += Sums(pos + 1, val%d, rem-1,d);
    res += Sums(pos + 1, modValue, rem,d);

    return res;
}


int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        memset(dp, -1 , sizeof dp);
        int q;
        scan(n);scan(q);
        rep1(i,n)
        {
            int a;
            scan(a);
            v.push_back(a);
        }
        printf("Case %d:\n",t);
        while(q--)
        {
            int m,d;
            scan(d);
            scan(m);
            printf("%lld\n",Sums(0,0,m,d));
        }

        v.clear();

    }
}

