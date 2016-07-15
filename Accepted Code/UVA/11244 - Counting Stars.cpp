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
    char star[105][105];

    while(1)
    {
        int m,n;
        cin>>m>>n;
        if(m==0 && n==0)
            break;
        string s;

        for(int i=0;i<m;i++)
        {
            cin>>s;
            int j=1;
            for(int k=0;k<s.size();k++)
                star[i][k] = s[k];
        }
        int cnt =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(star[i][j]=='*')
                {
                    if(i>0 && j>0)
                        if(star[i-1][j-1]=='*')
                            continue;

                    if(i<m-1 && j<n-1)
                        if(star[i+1][j+1] == '*')
                            continue;
                    if(i>0 && j<n-1)
                        if(star[i-1][j+1]=='*')
                            continue;
                    if(i<m-1 && j>0)
                        if(star[i+1][j-1] == '*' )
                            continue;
                    if(j<n-1)
                        if(star[i][j+1]=='*')
                            continue;
                    if(j>0)
                        if(star[i][j-1]=='*')
                            continue;
                    if(i<m-1)
                        if(star[i+1][j]=='*')
                            continue;
                    if(i>0 )
                        if(star[i-1][j]=='*')
                            continue;
                        cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
