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
    while(getline(cin,s))
    {
        string t;
        t.clear();
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>64 && s[i]<91) || (s[i]>96 && s[i]<123))
                t.push_back(s[i]);
            else
            {
                if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u' || t[0]=='A' || t[0]=='E' || t[0]=='I' || t[0]=='O' || t[0]=='U' )
                {
                    cout<<t<<"ay";
                }
                else if(t.size()!=0)
                {
                    for(int j=1; j<t.size(); j++)
                        cout<<t[j];
                    cout<<t[0]<<"ay";
                }
                cout<<s[i];
                t.clear();
            }
        }
        if(t.size()!=0)
        {
            if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u' || t[0]=='A' || t[0]=='E' || t[0]=='I' || t[0]=='O' || t[0]=='U' )
            {
                cout<<t<<"ay";
            }
            else
            {
                for(int j=1; j<t.size(); j++)
                    cout<<t[j];
                cout<<t[0]<<"ay";
            }
            t.clear();
        }
        cout<<endl;
    }
    return 0;
}
