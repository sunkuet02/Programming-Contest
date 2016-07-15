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
int parent[200005];
int find_parent(int a)
{
    if(parent[a]==a)
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}
int main()
{
    int m,n;
    int highest[200005];
    int te;
    cin>>te;
    map<string,int>mp;
    for(int t=1;t<=te;t++)
    {
        cin>>m;
        int in = 1;
        for(int i=1;i<=2*m;i++)
        {
            parent[i] = i;
            highest[i] = 1;
        }
        for(int i=1;i<=m;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
                mp[s1] = in++;
            if(mp.find(s2)==mp.end())
                mp[s2] = in++;

            int p = find_parent(mp.find(s1)->second);
            int q = find_parent(mp.find(s2)->second);
            if(p!=q)
            {

                if(highest[p]>=highest[q])
                {
                    parent[q] = p;
                    highest[p]+=highest[q];
                    cout<<highest[p]<<endl;
                }
                else if(highest[q]>highest[p])
                {
                    parent[p] = q;
                    highest[q]+=highest[p];
                    cout<<highest[q]<<endl;
                }
            }
            else
                cout<<highest[p]<<endl;
        }
        mp.clear();
    }
    return 0;
}
