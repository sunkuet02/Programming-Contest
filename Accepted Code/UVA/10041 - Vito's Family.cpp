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
    vector<int>v;
    for(int test =1;test<=t;test++)
    {
        int tt;
        cin>>tt;
        int total =0;
        for(int te=1;te<=tt;te++)
        {
            int m;
            cin>>m;
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        int mid = tt/2;
        for(int i=0;i<mid;i++)
        {
            total +=(v[mid]-v[i]);
        }
        for(int i=mid+1;i<v.size();i++)
        {
            total +=(v[i]-v[mid]);
        }
        cout<<total <<endl;
        v.clear();
    }
    return 0;
}
