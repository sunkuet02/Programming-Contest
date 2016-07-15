 #include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n = 30;
//int w = 150;
int dp[35][155];
int cost[35];
int w[35];
int dir[35][35];

int knapsack(int i,int remaining)
{
    if(i>n)
        return 0;
    if(dp[i][remaining]!=-1)
    {
        return dp[i][remaining];
    }
    int profit1,profit2;
    profit1=profit2=0;

    if(w[i]<=remaining)
        profit1 = cost[i] + knapsack(i+1,remaining - w[i]);
    profit2 = knapsack(i+1,remaining);
//    return
//        dp[i][remaining] = max(profit1,profit2);

    if(profit1>profit2)
    {
        dir[i][remaining] = 1;
        return dp[i][remaining] = profit1;
    }
    else
    {
        dir[i][remaining] = 2;
        return dp[i][ remaining] = profit2;
    }


}

int main()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int bag_size;
    cin>>n>>bag_size;
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i]>>w[i];
    }
    int ret  = knapsack(1,bag_size);
    cout<<ret<<endl;
//    while(1)       /******************For printing The Path ******************/
//    {
//        if(dir[i][j]==-1)
//            break;
//        if(dir[i][j]==1)
//        {
//            cout<<i<<ends;
//            j = j -w[i];
//        }
//        i++;
//    }
}
