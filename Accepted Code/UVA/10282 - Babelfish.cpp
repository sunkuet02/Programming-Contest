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
    map<string,string>mp;
    string s,s1,s2;
    while(getline(cin,s))
    {
        if(s.empty())
            break;
        int i;
        for( i=0;s[i]!=' ';i++)
            s1.push_back(s[i]);
        i++;
        for(;s[i]!='\0';i++)
            s2.push_back(s[i]);
        mp[s2] = s1;
        s1.clear();
        s2.clear();
    }
    while(cin>>s)
    {
        if(mp.find(s)==mp.end())
            cout<<"eh"<<endl;
        else
            cout<<mp.find(s)->second<<endl;
    }
    mp.clear();
    return 0;
}
