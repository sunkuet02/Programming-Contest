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

int maxSubRect = -127*100*100;
int arr[200][200];
int n;


int maxSum()  // this gives wrong answer
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = i; k < n; k++)
                for (int l = j; l < n; l++)
                {
                    int subRect = arr[k][l];
                    if (i > 0) subRect += arr[i - 1][l];
                    if (j > 0) subRect += arr[k][j - 1];
                    if (i > 0 && j > 0) subRect -= arr[i - 1][j - 1];
                    maxSubRect = max(maxSubRect, subRect);
                }
    return maxSubRect;
}


int maxsum()     // this gives right answer
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = i; k < n; k++)
                for (int l = j; l < n; l++)
                {
                    int subRect = 0;
                    for (int a = i; a <= k; a++)
                        for (int b = j; b <= l; b++)
                            subRect += arr[a][b];
                    maxSubRect = max(maxSubRect, subRect);
                }
    return maxSubRect;
}
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }
        int r = maxsum();
        cout<<r<<endl;
    }

    return 0;
}
