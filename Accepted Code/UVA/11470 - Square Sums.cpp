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

int main()
{
    int grid[15][15];
    int m;
    //freopen("input.txt","r",stdin);
    int t=0;
    while(scanf("%d",&m) && m)
    {
        t++;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }
        int a = 0;
        int b = m-1;
        printf("Case %d:",t);
        for(;;)
        {
            int sum = 0;
            for(int j = a; j<=b; j++)
                sum+=grid[a][j];

            for(int i =a+1;i<=b;i++)
                sum+=grid[i][a];

            for(int i=a+1;i<=b;i++)
                sum+=grid[i][b];

            for(int j = a+1;j<b;j++)
                sum+=grid[b][j];

            cout<<" "<<sum;
            a++;
            b--;
            if(a>b) break;
        }
        cout<<endl;
    }
        return 0;
}
