#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);

#define mx 205
#define INF 9999999
using namespace std;

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(y>=2*x)
        {
            cout<<2<<endl;
            continue;
        }
        int t = y%x;
        int total = 1;

        if(t)
            total = x/t;

        int is = 0 ;
        if(x%t)
            is = 1;
        total += is;
        cout<<total+1<<endl;
    }
}
