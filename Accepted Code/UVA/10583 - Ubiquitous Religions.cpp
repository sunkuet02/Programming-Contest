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
int parent[50005];
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
    bool isfind[50005];

    int k=0;
    while(1)
    {
        k++;
        cin>>m>>n;
        if(m==0 && n==0)
            break;
        for(int i=1;i<=m;i++)
        {
            parent[i] = i;
            isfind[i] = false;
        }
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            int p = find_parent(a);
            int q = find_parent(b);
            if(p!=q)
            {
                parent[p] = q;
            }
        }
        for(int i=1;i<=m;i++)
        {
            int a = find_parent(i);
            parent[i] = a;
        }
        int total = 0;
        for(int i=1;i<=m;i++)
        {
            if(!isfind[parent[i]])
            {
                total ++;
                isfind[parent[i]] = true;
            }
        }
        cout<<"Case "<<k<<": "<<total<<endl;
    }
    return 0;
}
