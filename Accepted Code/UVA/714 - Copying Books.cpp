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
#define sz 1000002
#define mod 1000000007
#define MAX 10000005
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

int n, k ;
LL arr[505] ;

bool valid(LL val)
{
	if(arr[0] > val ) return false;

	int cnt = 1 ;
	LL total = arr[0] ;
	rep1(i,n-1)
	{
		if(arr[i] > val) return false;

		if(total + arr[i]> val)
		{
			cnt ++ ;
			total = arr[i];
		}
		else
		{
			total += arr[i];
		}
	}
	if(cnt <= k) return true;
	else return false;
}

vector<LL > v;

int main()
{
	int test;
	scan(test);

	rep1(t,test)
	{
		scan(n);
		scan(k);
		rep0(i,n) scanf("%lld",&arr[i]);

		LL lo = 0, hi = 10000000 * 500 ;
		LL ans ;
		while(lo<=hi)
		{
			LL mid = lo + (hi-lo)/2;
			if(valid(mid))
			{
				hi = mid-1;
				ans = mid;
			}
			else
			{
				lo = mid+1 ;
			}
		}

		LL total = arr[n-1] ;
		int cnt = 1 ;
		v.push_back(arr[n-1]);

		for(int i = n-2 ; i>=0 ; i--)
		{
			if(i + 1 == k - cnt)
			{
				v.push_back(0);
				v.push_back(arr[i]);
				cnt ++ ;
			}
			else if(total + arr[i] > ans)
			{
				cnt ++ ;
				v.push_back(0);
				total = arr[i];
				v.push_back(total) ;
			}
			else
			{
				total += arr[i];
				v.push_back(arr[i]);
			}
		}
		reverse(v.begin(), v.end());


		//rep0(i,v.size() ) cout << v[i] << ends;

		printf("%lld", v[0]);
		for(int i = 1 ; i< v.size() ; i++ )
		{
			if(v[i]==0)
			{
				printf(" /");
			}
			else
				printf(" %lld", v[i]);
		}
		cout << endl;
		v.clear();
	}
}

