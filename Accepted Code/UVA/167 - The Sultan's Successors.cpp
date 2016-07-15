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

int x[20];
vector<int>contain[100];
int q = 0;
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
    x[20] = {1};
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    NQueue(1,8);
    int te;
    cin>>te;
    int value[15][15];
    while(te--)
    {
        int row,column;

        for(int i = 0;i<8;i++)
            for(int j = 0;j<8;j++)
                cin>>value[i][j];

        int res = 0;
        for(int i = 0;i<92;i++)
        {
            int sum = 0;
                for(int j = 0;j<8;j++)
                    sum += value[j][contain[i][j]-1];
            if(sum>res)
                res = sum;

        }
        printf("%5d\n",res);

    }
    return 0;
}


