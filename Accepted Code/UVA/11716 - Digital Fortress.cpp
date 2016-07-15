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

    int is_square[10005] = {0};
    for(int i=1;i<=100;i++)
        is_square[i*i] = 1;
    int te ;
    cin>>te;
    getchar();
    for(int t=0;t<te;t++)
    {
        string s;
        getline(cin,s);
        int a=0;
        if(!is_square[s.size()])
        {
            cout<<"INVALID"<<endl;
        }
        else
        {
            int square = sqrt(s.size());
            for(int j = 0;j<square;j++)
            for(int i = j;i<s.size();i+=square)
            {
                cout<<s[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
