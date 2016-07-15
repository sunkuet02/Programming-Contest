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
    scanf("%d",&te);
    for(int t =1;t<=te;t++)
    {
        int redius;
        scanf("%d",&redius);

        int length,half_wide;
        length = 5*redius;
        half_wide = length*3/10;

        int left_length,right_length;
        left_length = length*45/100;
        right_length = length - left_length;

        printf("Case %d:\n",t);
        printf("-%d %d\n",left_length,half_wide);
        printf("%d %d\n",right_length,half_wide);
        printf("%d -%d\n",right_length,half_wide);
        printf("-%d -%d\n",left_length,half_wide);
    }
    return 0;
}
