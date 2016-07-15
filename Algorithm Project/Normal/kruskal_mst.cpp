#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int parent[100];
struct edge
{
    int u,v,w;
    bool operator <(const edge &p) const
    {
        return w<p.w;
    }
};
vector<edge>e;
int find_parent(int a)
{
    if(parent[a]==a) return a;
    return parent=find_parent(parent[a]);
}
int main()
{

}
