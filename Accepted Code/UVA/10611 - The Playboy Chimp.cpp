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

vector<int> v;
map<int, bool > mp;

int main()
{
	//READ();
	int n;
	while(scan(n)!=EOF)
	{
		v.clear();
		mp.clear();

		rep1(i,n)
		{
			int a;
			scan(a);
			if(mp.find(a)==mp.end())
				v.push_back(a);
			mp[a] = true;
		}
		int q;
		scan(q);
		while(q--)
		{
			int a;
			scan(a);
			int pos = lower_bound(v.begin() , v.end() , a) - v.begin();
			int f = -1, l = -1;
			if(pos == n  )
			{
				f = n-1;
			}
			else if( pos == n-1 && v[pos] == a)
			{
				f = n-2;
			}
			else if(pos == 0 && v[0] >  a)
			{
				l = 0;
			}
			else if(pos == 0 && v[0] ==  a)
			{
				l = 1;
			}
			else
			{
				if(v[pos] == a)
				{
					f = pos - 1;
					l = pos + 1;
				}
				else
				{
					f = pos - 1;
					l = pos ;
				}
			}
			if(f >=0 && f!=-1)
			{
				printf("%d ",v[f]);
			}
			else
				printf("%c ",char(88));
			if(l<n && l!=-1)
				printf("%d\n",v[l]);
			else
				printf("%c\n",char(88));
		}
	}
}

