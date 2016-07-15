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
class node
{
    public :
    int x,y,distance;
};
bool  visited[15][15];
node source,destinition;
int direction[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };
int knight()
{
    queue<node>q;
    while(!q.empty())
    {
        q.pop();
    }
    q.push(source);
    source.distance = 0;
    visited[source.x][source.y] = true;
    if(source.x == destinition.x && source.y ==destinition.y )
        return 0 ;
    while(!q.empty())
    {
        node f = q.front();
        q.pop();
        for(int i = 0;i<=7;i++)
        {
            node n;
            n.x = f.x +direction[i][0];
            n.y = f.y +direction[i][1];
            if(n.x == destinition.x && n.y == destinition.y)
                return f.distance +1;
            if(n.x<1 || n.y<1 || n.x>8 || n.y>8)
                continue;
            if(visited[n.x][n.y])
                continue;
            else
                n.distance = f.distance +1;
            q.push(n);
            visited[n.x][n.y] = true;
        }
    }
}
int main()
{
    string s1,s2;
    //freopen("input.txt","r",stdin);
    while(cin>>s1>>s2)
    {
        for(int i=0;i<=8;i++)
            for(int j=0;j<=8;j++)
                visited[i][j] = false;
        source.x = s1[0] - 96;
        source.y = s1[1] - 48;
        destinition.x = s2[0] - 96;
        destinition.y = s2[1] - 48;
        int ret = knight();
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<ret<<" knight moves."<<endl;
    }

    return 0;
}
