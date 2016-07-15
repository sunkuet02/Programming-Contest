#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//int coin[3] = {1,2,5};
//int dp[65000];
//
////This is for unknown number of coins
//int main()
//{
//    memset(dp,0,sizeof(dp));
//    dp[0 ] = 1;
//    for(int i=0;i<3;i++)
//    {
//        for(int j = coin[i] ;j<65001;j++)
//        {
//            dp[j] = dp[j] +dp[j-coin[i]];
//        }
//    }
//    while(1)
//    {
//        int a;
//        cin>>a;
//        cout<<"the remain count is : "<<dp[a]<<endl;
//    }
//    return 0;
//}

int coin[3] = {1,2,5};
int dp[10][65000];
int main()
{
    //how many ways to find
    //light oj 1231
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=0;i<3;i++)
        dp[i][0] = 1;
    for(int i=0;i<3;i++)
    {
        for(int j = 1;j<=65000;j++)
        {
            for(int k=1;k<=coin[i-1];k++)
            {
                int temp = j - k*coin[i-1];
                if(temp<0)
                    break;
                dp[i][j] = dp[i][j] + dp[i-1][temp];
            }
        }
    }
    return 0;
}
