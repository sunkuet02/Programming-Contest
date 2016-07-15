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
    //READ();
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int total = 0 ;
        for(int i = 0 ; i< n; i++ )
        {
            bool is = true;
            for(int j = 0 ; j< m ; j++ )
            {
                int a;
                scan(a);
                if(!a)
                    is = false;
            }
            if(is)
                total++;
        }
        cout<<total<<endl;

    }
}
