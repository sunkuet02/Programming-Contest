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
    int te;
    int contain_neighbour[1005];
    cin>>te;
    for(int t = 0;t<te;t++)
    {
        int P;
        cin>>P;
        int low_contain = 5000;
        getchar();
        string s;
        for(int m = 1;m<=P;m++)
        {
            int cnt = 0;
            getline(cin,s);
            for(int i = 0;i<s.size();i++)
            {
                if(s[i]==' ')
                    cnt++;
            }
            cnt++;
            if(cnt<low_contain)
                low_contain = cnt;

            contain_neighbour[m] = cnt;
        }
        int  i;
        for(i = 1;i<=P;i++)
            if(contain_neighbour[i]==low_contain)
            {
                cout<<i;
                break;
            }
        for(i = i+1;i<=P;i++)
            if(contain_neighbour[i] == low_contain)
                cout<<" "<<i;

        cout<<endl;
    }
    return 0;
}
