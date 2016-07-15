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
        double x0,x1,y0,y1,r,cx,cy;
        cin>>x0>>y0>>x1>>y1>>cx>>cy>>r;

        double ln = x1- x0, w = y1-y0;
        double tempx = (ln * 9.0)/20.0 ;
        double tempy = w / 2.0;
        double tempr = ln/5.0 ;
        //cout<<cx-tempx<<ends<<cy<<tempy<<ends<<r<<tempr<<endl;
        if(abs((w/ln)-0.6) >=0.0000001 || 2.0 * tempr > w )
        {
            cout<<"NO"<<endl;
        }
        else if(abs( cx -x0 - tempx)<= 0.0000001 && abs(cy -y0 - tempy)<=0.0000001 && abs(r - tempr)<= 0.0000001)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

}
