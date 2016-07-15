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
#define LL long long int
#define mx 15
#define MAX 15
using namespace std;

int main()
{
     int n;
     vector<int > contain;
     int test = 1;
     while(cin >> n)
     {
         string s;
         int cnt = 0;
         while(n--)
         {
             contain.clear();
             cin >> s;
             sort(s.begin(), s.end());
             int count = 1 ;
             for(int i = 1; i< s.size() ; i++ )
             {
                 if(s[i]==s[i-1])
                    count ++ ;
                 else
                 {
                     contain.push_back(count);
                     count = 1;
                 }
             }
             contain.push_back(count);
             sort(contain.begin() , contain.end());
             if(contain.size() >=2)
             {
                 int i = 1;
                 for(; i< contain.size() ; i++ )
                 {
                     if(contain[i]==contain[i-1])
                        break;
                 }
                 if(i==contain.size())
                    cnt ++ ;
             }
         }
         printf("Case %d: %d\n",test++, cnt);
     }
}
