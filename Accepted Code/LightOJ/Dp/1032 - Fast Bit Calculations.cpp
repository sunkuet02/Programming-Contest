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
LL dp[50][3][3][32];
LL Bits( int pos, int last, int isequal,int cnt1)
{
    if(pos == v.size())
        return cnt1;

    LL  &res = dp[pos][last][isequal][cnt1];
    if(res!=-1) return res;

    res = 0 ;
    if(isequal)
    {
        for(int i = 0 ; i<= v[pos] ; i++ )
        {
            if(i<v[pos])
                res += Bits( pos +1 , i, 0,cnt1);
            else if(last ==1 && i==1)
                res += Bits( pos +1 , i, 1, cnt1+1);
            else
                res += Bits( pos +1 , i, 1, cnt1);
        }
    }
    else
    {
        for(int i = 0 ; i<=1 ; i++ )
        {
            if(last ==1 && i==1)
                res += Bits( pos +1 , i, 0, cnt1+1);
            else
                res += Bits( pos +1 , i, 0, cnt1);
        }
    }

    return  res ;
}
int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        memset(dp, -1 , sizeof dp);
        int n;
        scan(n);
        v = intToBinary(n);

        LL res = 0 ;
        res += Bits(1, 0,0,0);
        res += Bits(1,1,1,0);
        printf("Case %d: %lld\n",t,res);
        v.clear();

    }
}

