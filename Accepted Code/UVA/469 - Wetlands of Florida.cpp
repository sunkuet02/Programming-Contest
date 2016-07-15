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
int m,n;
int cnt;
int DFS(int x,int y)
{
    if(x<0 || x>m-1 )
        return 0;
    if(y<0 || y>n-1)
        return 0;
    if(graph[x][y] == 'L' || visited[x][y])
        return 0;
    visited[x][y] = true;
    cnt++;
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
    int te;
    cin>>te;
    string s;
    getchar();
    getchar();
    for(int t = 0;t<te;t++)
    {
        m = 0;
        n = 0;
        if(t!=0)
           cout<<endl;
        while(getline(cin,s))
        {

            if(s=="")
                break;
            if(n ==0)
                n = s.size();

            if(s[0]=='L' || s[0]=='W')
            {
                for(int i = 0;i<n;i++)
                    graph[m][i] = s[i];
                m++;
            }
            else
            {
                memset(visited,false,sizeof(visited));
                cnt =0;
                int x = 0,y = 0;
                int temp = 0;
                int i = 0;
                while(s[i]==' ')
                    i++;
                while(s[i]!=' ')
                {
                    temp = temp*10 +(s[i]-48);
                    i++;
                }
                x = temp;
                temp = 0;
                while(s[i] == ' ')
                    i++;
                while(s[i]!='\0')
                {
                    temp = temp*10 +(s[i] - 48);
                    i++;
                }
                y = temp;
                DFS(x-1,y-1);
                cout<<cnt<<endl;
            }
        }
    }

    return 0;
}
