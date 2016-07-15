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
#include <utility>

using namespace std;

class input
{
    public :
    double x1,x2,y1,y2;
};
int main()
{
    //freopen("input.txt","r",stdin);
    vector<input>v;
    char ch;
    while(1)
    {
        input in;
        cin>>ch;

        if(ch=='*')
            break;

        else if(ch=='r')
        {
            cin>>in.x1>>in.y1>>in.x2>>in.y2;

        }
        v.push_back(in);
    }
    double x,y;
    int t =0;
    while(1)
    {
        t++;
        cin>>x>>y;

        if(x==9999.9 && y == 9999.9)
            break;
        int flag = 0;
        for(int i =0;i<v.size();i++)
        {
            input in;

            in = v[i];


            {
                if((x>in.x1 && x<in.x2)&&(y>in.y2 && y<in.y1))
                {
                    printf("Point %d is contained in figure %d\n",t,i+1);
                    flag ++;
                }
            }

        }
        if(!flag)
            printf("Point %d is not contained in any figure\n",t);
    }

}

