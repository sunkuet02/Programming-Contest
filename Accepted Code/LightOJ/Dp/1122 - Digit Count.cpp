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
#define mx 100005
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
/****************************Z algorithm ************************/
/*
int z[mx] ;
string s;
bool zAlgorithm(int m)
{
    int n = s.size();
    int cnt = 0 ;
    int L = 0, R = 0;
    z[0] = 0 ;
    for (int i = 1; i <= n-m; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R-L] == s[R])
                R++;
            z[i] = R-L;
            R--;
        }
        else
        {
            int k = i-L;
            if (z[k] < R-i+1)
                z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R-L] == s[R])
                    R++;
                z[i] = R-L;
                R--;
            }
        }
        if(z[i]==m)
            return true;

    }
    return false;
}

*/
/**************************Implement***********************/

vector<int> v;
int n;
int dp[15][15] ;

int Count(int pos, int last)
{
    if(pos == n)
    {
        return 1;
    }
    int &res = dp[pos][last] ;
    if(res!=-1) return res ;

    res = 0 ;
    for(int i = 0 ; i< v.size(); i++ )
    {
        if(abs(v[i]-last) <=2)
        {
            res += Count(pos + 1, v[i]);
        }
    }
    return res ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    scan(test);
    rep1(t,test)
    {
        memset(dp, -1, sizeof dp);

        int m;
        scan(m);scan(n);
        rep1(i,m)
        {
            int a;
            scan(a);
            v.push_back(a);
        }
        sort(v.begin(), v.end()) ;
        int ret = 0;

        for(int i = 0 ; i< v.size() ; i++ )
        {
            ret += Count(1,v[i]);
        }

        printf("Case %d: %d\n",t,ret);
        v.clear();
    }

}

