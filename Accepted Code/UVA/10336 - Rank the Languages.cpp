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
char language[10000][10000];
bool visited[10000][10000];
int m,n;
char ch;
int contain[130],contain_visit[130];
int DFS(int i,int j)
{
    if(i<0 || i>=m || j<0 || j>=n)
        return 0;
    if(visited[i][j])
        return 0;
    if(ch!= language[i][j])
        return 0;
    visited[i][j] = true;
    DFS(i,j+1);
    DFS(i,j-1);
    DFS(i+1,j);
    DFS(i-1,j);

    return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int te;
    cin>>te;
    vector<char>vec;
    vector<pair<int,char> >v;
    for(int t=1;t<=te;t++)
    {
        memset(contain,0,sizeof(contain));
        memset(contain_visit,0,sizeof(contain_visit));
        cin>>m>>n;
        string s;
        for(int i=0;i<m;i++)
        {
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                visited[i][j] = false;
                language[i][j] = s[j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    ch = language[i][j];
                    if(!contain_visit[ch])
                    {
                        vec.push_back(ch);
                        contain_visit[ch] = 1;
                    }
                    DFS(i,j);
                    contain[ch]++;
                }
            }
        }
        printf("World #%d\n",t);
        for(int i=0;i<vec.size();i++)
        {
            v.push_back(make_pair(contain[vec[i]],vec[i]));
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++)
        {
            int j = i;
            int a = v[i].first;
            while(v[i].first==a)
                i++;

            for(int k = i-1;k>=j;k--)
                printf("%c: %d\n",v[k].second,v[k].first);
            i--;


        }
        vec.clear();
        v.clear();
    }
    return 0;
}
