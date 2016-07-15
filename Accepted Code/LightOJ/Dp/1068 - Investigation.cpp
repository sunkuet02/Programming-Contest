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
#define MAX 10000005
#define sz 100005
using namespace std;

typedef pair<int, int> pii;


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

using namespace std;

int dp[15][100][100][3];
string str;
int k;

int investigate(int pos , int modsum, int modmul, bool mark)
{
    int &res = dp[pos][modsum][modmul][mark] ;

    if(res!=-1) return dp[pos][modsum][modmul][mark] ;

    res = 0 ;
    if(pos == str.size() )
    {
        if(modsum ==0 && modmul ==0)
            res = 1;
    }
    else
    {
        modmul *=10;

        if(mark)
        {

            for(int i = 0 ; i<= str[pos] - '0' ; i++ )
            {
                if(i == str[pos] - '0')
                {
                    res += investigate(pos + 1, (modsum + i)%k, (modmul + i)%k , 1);
                }
                else
                {
                    res += investigate(pos + 1, (modsum+i)%k,(modmul + i)%k ,0);
                }
            }
        }
        else
        {
            for(int i =0;  i<10 ; i++ )
            {
                res += investigate(pos + 1, (modsum + i)%k,(modmul + i)%k , 0);
            }
        }
    }
    return res ;

}


int main()
{
    //READ();
    int test;
    scan(test);
    for(int t = 1; t<= test; t++)
    {
        memset(dp, -1 , sizeof(dp));

        int s1, s2 ;
        int cnt ;
        cin >> s1 >> s2 >> k;
        if(k>90)
            cnt = 0 ;
        else
        {
            str = NumberToString(s2);
            int a = investigate(0,0,0,1) ;

            memset(dp, -1 , sizeof(dp));
            str = NumberToString(s1-1);
            int b= investigate(0,0,0,1);

            cnt = a- b;
        }
        printf("Case %d: %d\n",t,cnt);
    }

}

