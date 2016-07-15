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
    map<int ,int>mp;
    vector<int>v;
    while(scanf("%d",&m)!=EOF)
    {
        if(!mp[m])
        {
            mp[m] = 1;
            v.push_back(m);
        }
        else
            mp[m]++;
    }
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" "<<mp[v[i]]<<endl;
    mp.clear();
    v.clear();

    return 0;
}
