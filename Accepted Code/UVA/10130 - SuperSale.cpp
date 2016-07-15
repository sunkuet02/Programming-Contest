#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;
int n;
int dp[1005][1005];
int cost[1005];
int w[1005];

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
    return
        dp[i][remaining] = max(profit1,profit2);
}

int main()
{
    int te;
    //freopen("input.txt","r",stdin);
    cin>>te;
    for(int t = 1;t<=te;t++)
    {
        memset(dp,-1,sizeof(dp));
        int bag_size;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i]>>w[i];
        }
        int m;
        int total = 0;
        cin>>m;
        for(int i = 1;i<=m;i++)
        {
            //memset(dp,-1,sizeof(dp));
            cin>>bag_size;
            int ret  = knapsack(1,bag_size);
            total += ret;
        }
        cout<<total<<endl;
    }


    return 0;
}
