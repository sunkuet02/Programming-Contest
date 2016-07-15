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

int parent[1000];
vector< pair< double, pair<int,int > > >city;
double bus_cost , train_cost;

int find_representative(int m)
{
    if(parent[m]==m)
        return m;
    else
        return parent[m] = find_representative(parent[m]);
}

int Finding_Cost(int m,int high)
{
    double high_cost = double(high);
    sort(city.begin(),city.end());
    for(int i=0; i<=m; i++)
        parent[i]=i;

    int cn =0;
    bus_cost = 0.0;
    train_cost = 0.0;
    int num_city=  0;
    for(int i=0; i<(int)city.size(); i++)
    {
        int p = find_representative(city[i].second.first);
        int q = find_representative(city[i].second.second);

        if(p!=q)
        {
            if(city[i].first<high_cost)
            {
                bus_cost += city[i].first;
            }
            else
            {
                train_cost +=city[i].first;
                num_city++;
            }
            parent[p] = q;
            cn++;
            if(cn == m-1)
                return num_city;
        }
    }
}

int main()
{
    int m,n,high_cost;
    //freopen("input.txt","r",stdin);
    int test ;
    scanf("%d",&test);
    vector<pair<int,int> >v;
    for(int t = 1; t<=test; t++)
    {
        city.clear();
        v.clear();

        cin>>m>>high_cost;
        for(int i =1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            for(int j =0;j<i-1;j++)
            {

                double dist = sqrt((double)((a-v[j].first)*(a-v[j].first) + (b-v[j].second)*(b-v[j].second)));
               // cout<<i<<ends<<j+1<<ends<<dist<<endl;

                city.push_back(make_pair(dist,make_pair(i,j+1)));
            }
            v.push_back(make_pair(a,b));
        }
        int num_city = Finding_Cost(m,high_cost);


        bus_cost += 0.5;
        train_cost +=0.5;

        int bus = int(bus_cost);
        int train = int(train_cost);

        printf("Case #%d: %d %d %d\n",t,num_city+1,bus,train);


    }
    return 0;
}


