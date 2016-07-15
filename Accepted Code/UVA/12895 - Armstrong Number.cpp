   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  Codeforces: sun.  , Topcoder : sun.
   *  Uva: sun. , SPOJ : sun_kuet  , LOJ : 5002 CodeChef: sun_kuet
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL long long int
#define mx 1005
using namespace std;

LL fact[21];
int f()
{
    fact[0] = 1;
    for(int i = 1; i<=20 ; i++ )
    {
        fact[i] = fact[i-1]*i;
    }
}

int main()
{
    int test;
    scan(test);
    rep1(t,test)
    {
        LL a;
        cin>>a;

        LL b = a;
        LL sum = 0 ;
        LL n = 0;
        while(b)
        {
            n++;
            b/=10;
        }
        b =a;
        while(b)
        {
            LL temp = 1;
            rep1(i,n) temp *= (b%10L);
            sum+= temp;
            b/=10;
        }
        //cout<<n<<ends<<sum<<endl;
        if(sum==a)
        {
            cout<<"Armstrong"<<endl;
        }
        else
        {
            cout<<"Not Armstrong"<<endl;
        }

    }

}
