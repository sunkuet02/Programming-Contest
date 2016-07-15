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
    public:
        int x,y,value;
};

int R,C;
bool bomb[1010][1010],visited[1010][1010];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1} };
node source,destinition;
int grid_bfs()
{
    queue<node>q;
    while(!q.empty())
        q.pop();
    source.value = 0;
    q.push(source);
    int total  = 0;
    visited[source.x][source.y] = true;
    while(!q.empty())
    {
        node f = q.front();
        q.pop();
        for(int i = 0;i<4;i++)
        {
            node n;

            n.x = f.x +dir[i][0];
            n.y = f.y +dir[i][1];
            if(n.x==destinition.x && n.y ==destinition.y)
                return f.value+1;
            if(n.x<0 || n.y <0 || n.x >=R  || n.y >=C)
                continue;
            if(bomb[n.x][n.y] || visited[n.x][n.y])
            {
                continue;
            }
            if(!visited[n.x][n.y])
                n.value = f.value+1;
            q.push(n);
            visited[n.x][n.y] = true;
        }

    }
}
int main()
{
    while(1)
    {
        cin>>R>>C;
        if(R==0 && C ==0)
            break;
        for(int i=0;i<=R;i++)
            for(int j=0;j<=C;j++)
            {
                bomb[i][j] = false;
                visited[i][j] = false;
            }
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int m,coun;
            cin>>m;
            cin>>coun;
            for(int j=0;j<coun;j++)
            {
                int a;
                cin>>a;
                bomb[m][a] = true;
            }
        }
        cin>>source.x>>source.y;
        cin>>destinition.x>>destinition.y;

        int ret = grid_bfs();
        cout<<ret<<endl;
    }

    return 0;
}
