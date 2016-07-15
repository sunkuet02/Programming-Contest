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
    int highest[50005];
    bool isfind[30005];
    int te;
    //freopen("input.txt","r",stdin);
    cin>>te;
    for(int t=1;t<=te;t++)
    {
        cin>>m>>n;
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
                parent[q] = p;
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
            int k=0;
            for(int j=1;j<=m;j++)
            if(!isfind[parent[j]])
            {
                if(parent[i]==parent[j])
                    k++;
            }
            if(total<k)
                total = k;
        }
        cout<<total<<endl;
    }
    return 0;
}
