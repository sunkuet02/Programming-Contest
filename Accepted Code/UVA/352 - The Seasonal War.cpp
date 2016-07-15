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

char oil[105][105];
bool visited[105][105];
int m;

int DFS(int x,int y)
{
    if(x<0 || x>m-1 )
        return 0;
    if(y<0 || y>m-1)
        return 0;
    if(oil[x][y] == '0' || visited[x][y])
        return 0;
    visited[x][y] = true;
    DFS(x,y+1);

    DFS(x,y-1);
    DFS(x+1,y);
    DFS(x-1,y);
    DFS(x+1,y+1);
    DFS(x+1,y-1);
    DFS(x-1,y-1);
    DFS(x-1,y+1);

    return 0;
}
int main()
{

    //freopen("input.txt","r",stdin);
    int t=0;
    while(scanf("%d",&m)!=EOF)
    {
        t++;
        string s;

        for(int i=0;i<m;i++)
        {
            cin>>s;
            int j=1;
            for(int k=0;k<s.size();k++)
            {
                oil[i][k] = s[k];
                visited[i][k] = false;
            }
        }
        int cnt =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(oil[i][j]=='1' && !visited[i][j])
                {
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",t,cnt);
    }
    return 0;
}
