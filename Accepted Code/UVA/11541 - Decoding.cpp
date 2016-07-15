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
    int te ;

    cin>>te;
    getchar();
    for(int t=1; t<=te; t++)
    {
        string s;
        cin>>s;
        int total =0;
        char ch='a';
        cout<<"Case "<<t<<": ";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                for(int j=0; j<total; j++)
                    cout<<ch;
                ch = s[i];
                total =0;
            }
            else
            {
                total = total *10 +(s[i]-48);
            }
        }
        for(int j=0; j<total; j++)
            cout<<ch;
        cout<<endl;
    }
    return 0;
}
