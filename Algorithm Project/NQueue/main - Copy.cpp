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
                    cout<<p<<ends<<x[p]<<endl;
                    cout<<endl;
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
    cout<<cn++<<endl;
    return 0;
}
