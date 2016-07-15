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
    int t;
    cin>>t;
    for(int te=0;te<t;te++)
    {
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        if(m ==0 )
        {
            printf("Yes\n");
            continue;
        }
        int c =0,d=0;
        for(;;)
        {
            sort(v.rbegin(),v.rend());
            if(c==1 || v[v.size()-1]<0)
            {
                printf("No\n");
                break;
            }
            else if(v[0]==0)
            {
                printf("Yes\n");
                break;
            }

            if(d ==0 && v[0]>=v.size())
            {
                printf("No\n");
                break;
            }
            d++;
            int p = v[0];
            v[0] = 0;
            for(int i =1;i<=p;i++)
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
