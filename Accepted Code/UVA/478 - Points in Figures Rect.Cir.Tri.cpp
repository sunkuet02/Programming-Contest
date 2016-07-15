

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
    char ch;
    double x1,x2,y1,y2,x3,y3,r;
};
int main()
{
    //freopen("output.txt","r",stdin);
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
        else if(ch=='c')
        {
            cin>>in.x1>>in.y1>>in.r;
        }
        else if(ch=='t')
        {
            cin>>in.x1>>in.y1>>in.x2>>in.y2>>in.x3>>in.y3;
        }

        in.ch = ch;
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

            if(in.ch=='r')
            {
                if((x>in.x1 && x<in.x2)&&(y>in.y2 && y<in.y1))
                {
                    printf("Point %d is contained in figure %d\n",t,i+1);
                    flag ++;
                }
            }
            else if(in.ch=='c')
            {
                double temp = sqrt((in.x1 - x )*(in.x1 - x) + (in.y1-y)*(in.y1 - y));

                if(temp<in.r)
                {
                    printf("Point %d is contained in figure %d\n",t,i+1);
                    flag++;
                }
            }
            else if(in.ch=='t')
            {
                double lph = ((in.y2 - in.y3)*(x-in.x3) + (in.x3 - in.x2)*(y-in.y3))/((in.y2 - in.y3)*(in.x1- in.x3) + (in.x3-in.x2)*(in.y1 - in.y3));
                double bet = ((in.y3 - in.y1)*(x - in.x3) +(in.x1 - in.x3)*(y - in.y3))/((in.y2 - in.y3)*(in.x1 - in.x3)+(in.x3 - in.x2)*(in.y1 - in.y3));
                double gm = 1.0 - lph - bet;
                if(lph> 0.0 && bet>0.0 && gm>0.0)
                {
                    printf("Point %d is contained in figure %d\n",t,i+1);
                    flag++;
                }
            }

        }
        if(!flag)
            printf("Point %d is not contained in any figure\n",t);
    }

}
