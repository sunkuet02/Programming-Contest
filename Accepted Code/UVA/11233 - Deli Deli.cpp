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
    int m,n;
    map<string,string>mp;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            mp[s1]=s2;
        }
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            if(mp.find(s)!=mp.end())
                cout<<mp.find(s)->second<<endl;
            else if((s[s.size()-1]=='y')&& (s[s.size()-2]!='a' && s[s.size()-2]!='e' && s[s.size()-2]!='o' && s[s.size()-2]!='i' && s[s.size()-2]!='u'))
            {
                for(int j=0;j<s.size()-1;j++)
                    cout<<s[j];
                cout<<"ies"<<endl;
            }
            else if(s[s.size()-1]=='o' || s[s.size()-1]=='s' || s[s.size()-1]=='x')
                cout<<s<<"es"<<endl;
            else if((s[s.size()-2]=='c' && s[s.size()-1]=='h')||(s[s.size()-2]=='s' && s[s.size()-1]=='h'))
                cout<<s<<"es"<<endl;
            else
                cout<<s<<"s"<<endl;
        }
        mp.clear();
    }
    return 0;
}
