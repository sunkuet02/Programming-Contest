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
    multiset<int>mset;
    multiset<int >::iterator it;

    int a;
    while(scanf("%d",&a)&&a)
    {
        int total=0;
        int m;
        for(int i=0;i<a;i++)
        {
            cin>>m;
            mset.insert(m);
        }
        while(mset.size()!=1)
        {
            int f,s;
            it = mset.begin();
            f = *it;
            mset.erase(it);
            it = mset.begin();
            s = *it;
            mset.erase(it);
            total = total +(f+s);
            mset.insert(f+s);

        }
        cout<<total<<endl;
        mset.clear();
    }
    return 0;
}
