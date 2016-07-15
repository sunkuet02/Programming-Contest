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
    for(int te=0;te<t;te++)
    {
        int m;
        string s;
        cin>>m;
        cin>>s;
        int re = 0;
        for(int i=0;i<s.size();i++ )
        {
            re = re*10 + (s[i]-48);

            if(re>m)
            {
                re = re %m;
            }
        }
        cout<<re<<endl;
    }
    return 0;
}
