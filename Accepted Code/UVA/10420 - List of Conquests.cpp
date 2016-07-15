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
    int a;
    cin>>a;
    set<string>st;
    set<string>::iterator it;
    vector<string>v;
    for(int i=0;i<a;i++)
    {
        string s,temp;
        cin>>s;
        getline(cin,temp);
        v.push_back(s);
        st.insert(s);
    }
    sort(v.begin(),v.end());
    for(it=st.begin();it!=st.end();it++)
    {
        int j=0;
        for(int i=0;i<v.size();i++)
        {
            if(*it==v[i])
                j++;
            else
            {
                if(j>0)
                    break;
            }
        }
        cout<<*it<<" "<<j<<endl;
    }
    st.clear();
    v.clear();
    return 0;
}
