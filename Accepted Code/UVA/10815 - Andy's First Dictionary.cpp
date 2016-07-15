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
    set<string>myset;
    set<string>::iterator it;
    string s,temp;
    vector<string>v;
    while(getline(cin,s))
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65 && s[i]<=90)
                s[i] = s[i]+32;

            if(s[i]>=97 && s[i]<=122)
                temp.push_back(s[i]);
            else if(temp.size()!=0 && !(s[i]>=97 && s[i]<=122))
            {
                myset.insert(temp);
                temp.clear();
            }
        }
        if(temp.size()!=0)
        {
                myset.insert(temp);
                temp.clear();
        }
    }
    for(it = myset.begin();it!=myset.end();it++)
        v.push_back(*it);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    v.clear();
    myset.clear();
    return 0;
}
