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
vector<int>word[205];

int Transformation(int s, int source,int destinition)
{
    bool taken[205];
    memset(taken,false,sizeof(taken));
    int dis[205];

    queue<int>q;
    q.push(source);
    dis[source] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i =0;i<word[u].size();i++)
        {
            int v = word[u][i];
            if(!taken[v])
            {
                dis[v] = dis[u]+1;
                if(v == destinition)
                    return dis[v];
                taken[v] = true;
                q.push(v);
            }
        }
    }

}

int main()
{
    int test;
    //freopen("input.txt","r",stdin);
    cin>>test;
    vector<string>v;
    for(int t =1; t<=test; t++)
    {
        v.clear();
        for(int i = 0;i<201;i++)
            word[i].clear();
        string s;
        while(1)
        {
            cin>>s;
            if(s=="*")
                break;
            for(int i =0 ; i<v.size(); i++ )
            {
                int cnt = 0;
                if(v[i].size()==s.size())
                {
                    for(int j =0; j<s.size(); j++)
                        if(v[i][j] != s[j])
                            cnt++;
                }
                if(cnt==1)
                {
                    word[i].push_back(v.size());
                    word[v.size()].push_back(i);
                }

            }
            v.push_back(s);
        }
        getchar();
        while(getline(cin,s) )
        {

            string temp1,temp2;
            if(s=="")
                break;
            int i;
            for(i =0; s[i]!=' '; i++)
            {
                temp1.push_back(s[i]);
            }
            for(i = i+1 ; i < s.size(); i++)
                temp2.push_back(s[i]);
            int t1,t2;

            for(int i=0;i<v.size();i++)
            {
                if(temp1 == v[i])
                    t1 = i;
                else if(temp2==v[i])
                    t2 = i;
            }
            cout<<temp1<<" "<<temp2<<" ";

            int ret = Transformation(v.size(),t1,t2);
            cout<<ret<<endl;

        }
        if(t!=test)
            cout<<endl;




    }
}


