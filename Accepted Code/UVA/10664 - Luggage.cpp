
#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define Read freopen("input.txt","r",stdin);
#define Write freopen("output.txt","w",stdout);
#define mem(a,val) memset(a,val, sizeof(a) );
#define LL long long int
#define mxx 65536
#define sz 200005
#define MAX 1300000

using namespace std;

typedef pair<int, int> pii;


template<class T> inline T power(T base, int p)
{
    T f = 1 ;
    for(int i=1 ; i<=p ; i++) f*=base;
    return f;
}
template <typename T>  string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

vector<int> stringToIntegerVector(string str) {
    vector<int> values;
    int n;
    stringstream stream(str);
    while(stream >> n){
        values.push_back(n);
    }
    return values;
}

int setbit(int N,int pos)
{
    return N = N|(1<<pos);
}
int resetbit(int N, int pos)
{
    return N = N & ~(1<<pos) ;
}
bool checkbit(int N,int pos)
{
    return (bool) (N & (1<<pos ) ) ;
}
int noofsetbits(int N)
{
    return __builtin_popcount (N);
}
/*****************Seive Prime********************/
/*
bool prime[MAX];
void seive()
{
    for(int i=2;i<=MAX;i++)
        prime[i]=true;
    for(int i=4;i<=MAX;i+=2) prime[i]=false;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }
}
*/
/******************** KMP ****************************/
/*
int kmpTemplateArray[100005];
void fillPatternTemplate(string str) {
    int j = 0;
    for(int i = 1 ; i < (int)str.size() ; i++ ) {
        if(str[i] == str[j]) {
            kmpTemplateArray[i] = j + 1;
            j++;
        }
        else {
            while(str[i] != str[j] && j) {
                j = kmpTemplateArray[j-1];
            }
            if(str[i] == str[j]) {
                kmpTemplateArray[i] = j + 1;
            } else {
                j = 0;
            }
        }
    }
}
int kmpSearch(string text, string pattern) {
    int j = 0 ;
    for(int i = 0 ; i< (int)text.size(); i++ ) {
        if(text[i] == pattern[j]) {
            j++ ;
        } 
        else {
            while(text[i] != pattern[j] && j) {
                j = kmpTemplateArray[j-1];
            }
            if(text[i] == pattern[j]) {
                j++;
            }
        }
        //cout <<text[i] << " " << pattern[j] << " " << i << " " << j << endl;
    }
    return j;
}
*/

/*********************nCr**************************/
/*
long long ncr[1005][1005];
void NCR()
{
    rep0(i,1003)
    {
        ncr[i][0] = 1;
    }
    rep(i,1, 1003)
    {
        rep(j,1,1003)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %=mod;
        }
    }
}
*/

LL bigMod(LL N,LL M,LL MOD)
{
    if(M==0) return 1;

    if((M/2)*2==M)
    {
        LL ret = bigMod(N,M/2,MOD)%MOD;
        return (ret*ret)%MOD;
    }
    else return ((N%MOD)*bigMod(N,M-1,MOD)%MOD)%MOD;
}

LL modInverseBigMod(LL a,LL m)  //a*x=1(mod m)
{
    return bigMod(a,m-2,m);
}

/****************************ExtendedEuclid&ModularInverse****/

pii extendedEuclid(LL a,LL b)
{
    if(b==0) return pii(1,0);
    pii d = extendedEuclid(b,a%b);
    return pii( d.second, d.first - d.second *(a/b) );
}
LL modularInverse(LL a,LL m)
{
    pii ret = extendedEuclid(a,m);
    return ( (ret.first % m) + m ) %m ;
}

/*********************temp_Definition *************************/

/***************************Implementation*********************/
#define limit 205

int dp[limit];

int main() {
    //Read;
    //freopen("out.txt", "w", stdout);
	int test;
	cin >> test;
    getchar();
	rep(t,1,test) {
		
        string s;
        getline(cin,s);
        mem(dp,0);
		
        vector<int> inputs = stringToIntegerVector(s);
        int n = inputs.size();
        
        int sum = 0;
        rep(i,0,n-1) sum += inputs[i];
		dp[0] = -1;
		
		rep(j,0,n-1) {
			int cur = inputs[j];
			rep(i,cur,sum) {
                if(dp[i-cur] && dp[i-cur] != cur && !dp[i]) {
                    dp[i] = cur;
				}
			}
            rep(i,cur,sum) {
                if(dp[i] == cur) {
                    dp[i] = -1;
				}
			}
		}
        
        if(sum%2 || !dp[sum/2]) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        			
	}
	
}
