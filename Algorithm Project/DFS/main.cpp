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

char graph[105][105];
bool visited[105][105];
int m;

int DFS(int x,int y)
{
    if(x<0 || x>m-1 )
        return 0;
    if(y<0 || y>m-1)
        return 0;
    if(graph[x][y] == '0' || visited[x][y])
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
    // INput the graph and call the function
    DFS(0,0);
    return 0;
}
