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
    int m;
    vector<int>v;
    while(scanf("%d",&m) && m)
    {
        for(int i=0;i<m;i++)
        {
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        int c =0,d=0;
        for(;;)
        {
            sort(v.rbegin(),v.rend());

            int m = v[0];
            v[0] = 0;
            for(int i =1;i<=m;i++)
            {
                v[i] = v[i] -1;
                if(v[i]<0)
                {
                    c=1;
                    break;
                }
            }
        }
        v.clear();
    }
    return 0;
}
