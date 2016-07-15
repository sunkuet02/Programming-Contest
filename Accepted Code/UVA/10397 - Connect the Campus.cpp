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
#include <utility>
using namespace std;

int parent[200005];
vector< pair< double , pair<int,int > > >disk;
vector<pair<double,double> >p_v;
int find_representative(int m)
{
    if(parent[m]==m)
        return m;
    else
        return parent[m] = find_representative(parent[m]);
}
double dijkstra_pair(int n)
{
    sort(disk.begin(),disk.end());
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int cnt =0;
    double total =0;
    for(int i=0;i<(int)disk.size();i++)
    {
        int u = find_representative(disk[i].second.first);
        int v = find_representative(disk[i].second.second);

        if(u!=v)
        {
            parent[u] = v;
            cnt++;
            total +=disk[i].first;
            if(cnt ==n-1) break;
        }
    }
    return total;
}
int main()
{
    int m,n;
    int t;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&m)!=EOF)
    {
        int xx,yy;
        double x,y;
        for(int i=1;i<=m;i++)
        {
            cin>>xx>>yy;
            x=(double)xx;
            y =(double)yy;
            for(int j=0;j<p_v.size();j++)
            {
                double cost =(double) sqrt((double)(abs(p_v[j].first-x)*abs(p_v[j].first-x))+(double)(abs(p_v[j].second-y)*abs(p_v[j].second-y)));
                disk.push_back(make_pair(cost,make_pair(i,j+1)));

            }
            p_v.push_back(make_pair(x,y));
        }
        int already,p,q;
        cin>>already;
        for(int i=0;i<already;i++)
        {
            cin>>p>>q;
            disk.push_back(make_pair(0.00,make_pair(p,q)));
        }
        double r = dijkstra_pair(m);
        printf("%.2lf\n",r);
        p_v.clear();
        disk.clear();
    }
    return 0;
}
