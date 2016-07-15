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
#include <utility>

using namespace std;

int main()
{
    vector<string>v;
    int p = 0;
    string s;
    int test;
    //freopen("input.txt","r",stdin);
    cin>>test;
    while(test--)
    {
        v.clear();
        p = 0;
        int m;
        cin>>m;
        getchar();
        for(int i =0; i<m; i++)
        {
            getline(cin,s);

            if(s=="LEFT")
            {
                p--;

                v.push_back(s);
            }
            else if(s=="RIGHT")
            {
                p++;
                v.push_back(s);
            }
            else
            {
                int num = 0;
                int j = s.size()-1;
                if(s[j-1]!= ' ')
                    num =(s[j-1]-48) *10 + (s[j]-48);
                else
                    num = s[j]-48;
                if(v[num-1]=="LEFT")
                {
                    p--;
                    v.push_back("LEFT");
                }
                else if(v[num-1]=="RIGHT")
                {
                    p++;
                    v.push_back("RIGHT");
                }

            }

        }

        cout<<p<<endl;
    }
}

