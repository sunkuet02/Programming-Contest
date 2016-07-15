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
vector<int>contain[1000];
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

    while(te--)
    {
        int row,column;
        cin>>row>>column;

        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;

        int c = 0;
        for(int i = 0;i<92;i++)
        {
            if(contain[i][column-1] == row)
            {
                printf("%2d      ",++c);
                cout<<contain[i][0];
                for(int j = 1;j<8;j++)
                    cout<<" "<<contain[i][j];
                cout<<endl;
            }

        }
        if(te!=0)
            cout<<endl;

    }
    return 0;
}

