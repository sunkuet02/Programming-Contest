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
    map<string,int>mp;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        string s,t;
        int value;
        for(int i=0; i<m; i++)
        {
            cin>>s>>value;
            mp[s] = value;
        }

        for(int j=0; j<n; j++)
        {
            int total = 0;
            for(;;)
            {
                getline(cin,s);
                if(s==".")
                    break;
                for(int i=0; i<s.size(); i++)
                {
                    if(s[i]==' ')
                    {
                        if(mp.find(t)!=mp.end())
                        {
                            total+=mp.find(t)->second;
                        }
                        t.clear();
                    }
                    else
                        t.push_back(s[i]);
                }
                if(mp.find(t)!=mp.end())
                {
                    total+=mp.find(t)->second;
                }
                t.clear();
            }
            cout<<total<<endl;
        }

        mp.clear();

    }
    return 0;
}
