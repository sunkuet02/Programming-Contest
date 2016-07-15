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

bool isvowel(char ch) { if(ch == 'A' || ch=='E' || ch =='I' || ch=='O' || ch =='U') return true; return false;}
string s;
int arr[55] ;
int dp[55][10][10] ;

bool bad , good;

int cal(int pos, int con1, int con0)
{
    if(con1 >=5 || con0 >=3)
    {
        return 1 ;
    }

    if(pos == s.size())
    {
        return 2 ;
    }

    int & res = dp[pos][con1][con0] ;
    if(res!=-1) return res;

    res = 0 ;
    if(arr[pos]==1)
    {
        res = cal(pos + 1, 0, con0 + 1) ;
    }
    else if(arr[pos]==0)
    {
        res = cal(pos + 1, con1 +1, 0);
    }
    else
    {
        int res1 = cal(pos + 1, 0,con0 + 1 );
        int res2 = cal(pos + 1, con1 + 1, 0 );
        if(res1!=res2) res = 3;
        else res = res1;
    }

    return res ;
}

bool stricklyBad()
{
    bool ans = false;

    int con1 = 0 , con0 = 0 ;
    for(int i = 0 ; i< s.size() ; i++ )
    {
        if(isvowel(s[i]))
        {
            con0 ++ ;
            con1 = 0;
        }
        else
        {
            con1 ++ ;
            con0 = 0 ;
        }
        if(con1==5)
            return 1;
        else if(con0==3)
            return 1;

    }
    return 0 ;

}

int main()
{
    //READ();
    int test ;
    scan(test);
    rep1(t,test)
    {
        bad = false; good = false;
        mem(arr,0);
        mem(dp, -1) ;

        cin >> s;
        rep0(i,s.size())
        {
            if(isvowel(s[i])) arr[i] = 1;
            else if(s[i]=='?') arr[i] = 2;
        }

        printf("Case %d: ",t);
        int ret = cal(0,0,0);

        if(ret == 3)
        {
            printf("MIXED\n");
        }
        else if(ret == 1)
        {
            printf("BAD\n");
        }
        else
        {
            printf("GOOD\n");
        }


    }
}


