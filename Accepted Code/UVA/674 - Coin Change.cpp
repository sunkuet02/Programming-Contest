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
int coin[5] = {1,5,10,25,50};
int value[8000];
int main()
{
    memset(value,0,sizeof(value));
    value[0] = 1;
    for(int i=0;i<5;i++)
        for(int j = coin[i];j<7490;j++)
            value[j] = value[j] + value[j - coin[i]];
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        cout<<value[a]<<endl;
    }
    return 0;
}
