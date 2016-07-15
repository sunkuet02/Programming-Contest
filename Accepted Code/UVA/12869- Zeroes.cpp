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
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL unsigned long long int
#define mod 1000000007
using namespace std;

LL zero(LL n)
{
   LL ans = 0 ;
    ans += (n/5L);
   return ans ;
}

int main()
{
    LL a,b;
    for(;;){
        scanf("%llu %llu",&a,&b);
            if(a==0 && b==0)
                break;
            LL first = zero(a);
            LL sec = zero(b);
           // cout<<first << ends << sec<< ends ;
            cout<<sec - first + 1<<endl;
    }
}

