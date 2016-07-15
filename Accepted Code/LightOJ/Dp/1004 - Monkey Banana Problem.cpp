#include<bits/stdc++.h>
#define m 105
#define scan(a) scanf("%d",&a)
using namespace std;

int dp[m][m] ;

vector<int> v[250];


int main()
{
    //freopen("input.txt","r",stdin);
    int te;
    scan(te);
    for(int t = 1 ; t<=te; t++)
    {
        int n;
        scan(n);

        for(int i=0 ; i<=2*n+2; i++)
            v[i].clear();

        for(int i = 0 ; i< n ; i++)
        {
            for(int j =0 ; j<= i ; j++ )
            {
                long long a;
                scan(a);
                v[i].push_back(a);
            }
        }
        for(int i = n ; i< 2*n -1 ; i++)
        {
            for(int j = n-1 ; j> i-n; j-- )
            {
                int a;
                scan(a);
                v[i].push_back(a);
            }
        }
//
//        for(int i = n ; i< 2*n-1 ; i++)
//        {
//            cout<<i<<ends;
//            for(int j =0 ; j<v[i].size() ; j++ )
//            {
//                printf("%d ", v[i][j]);
//            }
//            printf("\n");
//        }

            dp[0][0] = v[0][0];

            for(int i = 1 ; i<n; i++)
            {
                for(int j = 0 ; j<v[i].size() ; j++)
                {
                    if(j==0)
                        dp[i][0] = dp[i-1][0] + v[i][0];
                    else if(j==v[i].size()-1)
                        dp[i][j] = dp[i-1][j-1] + v[i][j];
                    else
                        dp[i][j] = v[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                }
            }

            for(int i = n ; i< 2*n - 1; i++)
            {
                for(int j = 0 ; j<v[i].size() ; j++)
                {

                    dp[i][j] = v[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                }
            }
            printf("Case %d: %d\n",t,dp[2*n-2][0]);

    }

    return 0;

}

