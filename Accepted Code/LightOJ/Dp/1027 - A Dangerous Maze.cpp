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




int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        int n ;
        scan(n);
        int noofminus = 0 , sum = 0 ;
        rep1(i,n)
        {
            int a;
            scan(a);
            if(a < 0)
            {
                noofminus ++ ;
                a *= (-1) ;
            }
            sum += a;
        }
        int Gcd = __gcd(sum, n - noofminus);
        printf("Case %d: ",t) ;
        if(noofminus == n)
        {
            printf("inf\n");
        }
        else
        {
            printf("%d/%d\n",sum/Gcd, (n-noofminus)/Gcd) ;
        }
    }
}

