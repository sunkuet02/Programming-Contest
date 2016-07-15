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
    vector<string>st;
    vector<int>in;
    for(int te =1;te<=t;te++)
    {
        string s;
        int m;
        for(int i=0;i<10;i++)
        {
            cin>>s>>m;
            st.push_back(s);
            in.push_back(m);
        }
        int high =0;
        for(int i =0;i<10;i++)
            if(high<in[i])
                high = in[i];
        cout<<"Case #"<<te<<":"<<endl;
        for(int i =0;i<10;i++)
            if(in[i]==high)
            cout<<st[i]<<endl;
        st.clear();
        in.clear();

    }
    return 0;
}
