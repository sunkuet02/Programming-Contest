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
#define mem(a,val) memset(a,val, sizeof(a) )
#define LL long long int
#define mx 50005
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
/****************************Implementation************************/



int main()
{
	int a,b;
	while(1)
	{
		scan(a);scan(b);
		if(a==1 && b ==1) break;



		double cur = 1.0;
		int upper = 1, lower = 1;
		char ch = 'L' ;
		int prvup = 0 , prvdown = 1;
		double actual = (double)(a)/(double)(b);
		if(a > b)
		{
			prvup = 1; prvdown = 0 ;
			ch = 'R';
		}

		char prev = 'C' ;
		while(1)
		{
			double d = (double)(upper)/(double)(lower);
			if(upper == a && lower == b) break;

			if(actual > d)
			{
				if(ch =='R')
				{
					lower = lower + prvdown;
					upper = upper + prvup;
				}
				else
				{
					int prvlower = lower, prvupper = upper ;
					lower = 2*lower - prvdown ;
					upper = 2*upper - prvup ;
					prvdown = (lower - prvlower); prvup = (upper - prvupper) ;
				}
				ch = 'R' ;
				cout << ch ;

			}
			else
			{
				if(ch=='L')
				{
					lower = lower + prvdown;
					upper = upper + prvup;
				}
				else
				{
					int prvlower = lower, prvupper = upper ;
					lower = 2*lower - prvdown ;
					upper = 2*upper - prvup ;
					prvdown = (lower - prvlower); prvup = (upper - prvupper) ;
				}
				ch = 'L';
				cout << ch;
			}
		}
		cout << endl;

	}
}

