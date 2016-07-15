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
int m,n;

int DFS(int x,int y)
{
    if(x<0 || x>m-1 )
        return 0;
    if(y<0 || y>n-1)
        return 0;
    if(oil[x][y] == '*' || visited[x][y])
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
    while(1)
    {
        cin>>m>>n;
        if(m==0 && n==0)
            break;
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
            for(int j=0;j<n;j++)
            {
                if(oil[i][j]=='@' && !visited[i][j])
                {
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
