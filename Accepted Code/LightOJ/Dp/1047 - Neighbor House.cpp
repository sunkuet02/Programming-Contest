
#include<bits/stdc++.h>
#define m 1005
#define Max 1000005
#define scan(a) scanf("%d",&a)
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int con[30][10] , res[30][10];
    int te;
    scan(te);
    for(int t  = 1 ;t<=te; t++)
    {
        int n;
        scan(n);

        for(int i = 0 ; i< n ;i++ )
        {
            for(int j = 0 ; j< 3 ; j++)
                scan(con[i][j]);
        }

        for(int j = 0 ; j< 3 ; j++)
                res[0][j] = con[0][j];

        for(int i = 1 ; i< n ;i++ )
        {
            res[i][0] = con[i][0] + min(res[i-1][1] , res[i-1][2]);
            res[i][1] = con[i][1] + min(res[i-1][0] , res[i-1][2]);
            res[i][2] = con[i][2] + min(res[i-1][1] , res[i-1][0]);
        }

        int ans = min(res[n-1][0] , min(res[n-1][1] , res[n-1][2]));
        printf("Case %d: %d\n",t,ans);
    }


}
