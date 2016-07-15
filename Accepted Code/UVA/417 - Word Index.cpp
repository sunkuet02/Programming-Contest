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
    string s;
    int count =0;
    map<string,int>mp;
    for(char i = 'a';i<='z';i++)
    {
        s.push_back(i);
        mp[s] = ++count;
        s.clear();
    }
    for(char i = 'a';i<='z';i++)
    {
        s.push_back(i);
        for(char j= i+1;j<='z';j++)
        {
            s.push_back(j);
            mp[s] = ++count;
            s.erase(s.size()-1);
        }
        s.clear();
    }
    for(char i  = 'a';i<='z';i++)
    {
        s.push_back(i);
        for(char j=i+1;j<='z';j++)
        {
            s.push_back(j);
            for(char k = j+1;k<='z';k++)
            {
                s.push_back(k);
                mp[s] = ++count;
                s.erase(s.size()-1);
            }
            s.erase(s.size()-1);
        }
        s.clear();
    }
    for(char i  = 'a';i<='z';i++)
    {
        s.push_back(i);
        for(char j=i+1;j<='z';j++)
        {
            s.push_back(j);
            for(char k = j+1;k<='z';k++)
            {
                s.push_back(k);
                for(char  l =k+1;l<='z';l++)
                {
                    s.push_back(l);
                    mp[s] = ++count;
                    s.erase(s.size()-1);
                }
                s.erase(s.size()-1);
            }
            s.erase(s.size()-1);
        }
        s.clear();
    }
    for(char i  = 'a';i<='z';i++)
    {
        s.push_back(i);
        for(char j=i+1;j<='z';j++)
        {
            s.push_back(j);
            for(char k = j+1;k<='z';k++)
            {
                s.push_back(k);
                for(char  l =k+1;l<='z';l++)
                {
                    s.push_back(l);
                    for(char m=l+1;m<='z';m++)
                    {
                        s.push_back(m);
                        mp[s] = ++count;
                        s.erase(s.size()-1);
                    }
                    s.erase(s.size()-1);
                }
                s.erase(s.size()-1);
            }
            s.erase(s.size()-1);
        }
        s.clear();
    }

    s.clear();
    while(cin>>s)
    {
        if(mp.find(s)==mp.end())
            cout<<"0"<<endl;
        else
            cout<<mp.find(s)->second<<endl;
    }
    return 0;
}
