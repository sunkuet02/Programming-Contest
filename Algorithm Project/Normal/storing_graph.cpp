    #include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
vector<int > graph[100];
int parent[100]={0};
vector<int >v;
int find_representative(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find_representative(parent[a]);
}
int find_node(int a,int b)
{
    if(parent[a]==b) return a;
    v.push_back(parent[a]);
    return parent[a]=find_node(parent[a],b);
}
void bfs(int source)
{
    queue<int>q;
    int taken[100]={0};
    q.push(source);
    int n=0;
    taken[source]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(!taken[v])
            {
                int a=find_representative(u);
                int b=find_representative(v);
                if(a!=b)
                    parent[v]=u;
                taken[v]=1;
                q.push(v);
            }

        }

        q.pop();
    }
}
int main()
{
    map<string,int>graph1;
    vector<string>v1,v2;
    set<string>s;
    set<string>::iterator it_set;
    string s1,s2;
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>s1>>s2;

        v1.push_back(s1);
        v2.push_back(s2);
        s.insert(s1);
        s.insert(s2);
    }
    int j=1;
    for(it_set=s.begin();it_set!=s.end();it_set++)
    {

        graph1[*it_set]=j++;
    }
    for(int i=0;i<a;i++)
    {
        graph[graph1.find(v1[i])->second].push_back(graph1.find(v2[i])->second);

    }
    cin>>s1>>s2;
    bfs(graph1.find(s1)->second);
    for(int i=1;i<j-1;i++)
    {

        a = find_representative(i);
        parent[i]=a;
    }
    //int node1=graph1.find(s1)->second;
    //int node2=graph1.find(s2)->second;
    //a=0;
    //for(int i=1;i<j;i++) cout<<parent[i];
    //find_node(node2,node1);
   // v.push_back(node1);
    cout<<graph1[0];
}
