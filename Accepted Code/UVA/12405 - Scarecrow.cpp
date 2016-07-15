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
    //freopen("input.txt","r",stdin);
    scanf("%d",&te);
    for(int t=1;t<=te;t++)
    {
        int m;
        scanf("%d",&m);
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='.')
        {
            cnt++;
            i +=2;
        }
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
