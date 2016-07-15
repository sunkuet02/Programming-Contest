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
    int t;

    cin>>t;
    for(int test =1;test<=t;test++)
    {
        int amp,freq;
        cin>>amp>>freq;
        for(int f=1;f<=freq;f++)
        {
            for(int i=1;i<=amp;i++)
            {
                for(int j=1;j<=i;j++)
                    cout<<i;
                cout<<endl;
            }
            for(int i=amp-1;i>0;i--)
            {
                for(int j=i;j>0;j--)
                    cout<<i;
                cout<<endl;
            }
            if(f!=freq)
                cout<<endl;

        }
        if(test!=t)
            cout<<endl;
    }
    return 0;
}
