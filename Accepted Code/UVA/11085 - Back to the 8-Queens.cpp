
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

int x[8] = {1};
vector<int>contain[92];

bool place(int k,int i)  // find if a quene can be placed
{
    for(int j= 1;j<k;j++)
    {
        if(x[j] == i)    // if same row
            return false;
        else if(abs(x[j]-i) == abs(j-k))    // if is same with diagonal
            return false ;

    }
    return true;
}
int cn = 0;
void NQueue(int k,int n)
{
    for(int i = 1;i <=8;i++)
    {
        if(place(k,i))
        {
            x[k] = i;

            if(k==n)
            {
                for(int p=1;p<=n;p++)       // finding the point
                contain[cn].push_back(x[p]);

                cn++;
            }
            else
                NQueue(k+1,n);     // find the next point
        }
    }
}


int main()
{
    NQueue(1,8);
    int v[12];
    int t = 0;
    while(scanf("%d %d %d %d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5],&v[6],&v[7])!=EOF)
    {
        t++;
        int mn = 20;
        for(int i = 0;i<92;i++)
        {
            int countt = 0;
            for(int j =0;j<8;j++)
            {
                if(contain[i][j]!=v[j])
                    countt++;
            }

            if(mn>countt)
                mn = countt;
        }
        printf("Case %d: %d\n",t,mn);
    }
    return 0;
}
