#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int graph[50]={0};
int find_representative(int a)
{
    if(graph[a]==a) return a;
    return graph[a]=find_representative(graph[a]);
}
int main()
{
    map<char , int>conver_node;
    int test_case;
    char highest;
    cin>>test_case;
    getchar();
    for(int test=1;test<=test_case;test++)
    {
        cin>>highest;
        int highest_value=highest-64;
        for(int letter=1;letter<=highest_value;letter++)
        {
            char q=letter+64;
           conver_node[q]=letter;
           graph[letter]=letter;
        }
        int node1,node2;
        string nodes;
        getchar();
        set<char>taken;
        int n=0,array[1500]={0},*pit,*qit;
        while(getline(cin,nodes))
        {
            if(nodes.size()==0) break;
            node1=conver_node.find(nodes[0])->second;
            node2=conver_node.find(nodes[1])->second;
            taken.insert(nodes[0]);
            taken.insert(nodes[1]);
            int a=find_representative(node1);
            int b=find_representative(node2);
            if(a!=b){
                 pit=find(array,array+2*n,a);
                qit=find(array,array+2*n,b);
                if(*pit)
                        graph[b]=a;
                else if(*qit)
                      graph[a]=b;
                else graph[b]=a;
                array[n++]=a;
                array[n++]=b;
            }
        }

        for(int i=1;i<=highest_value;i++)
        {
            int a=find_representative(i);
            graph[i]=a;
        }
        set<int>representatives;
       for(int i=1;i<=highest_value;i++)
        {
            representatives.insert(graph[i]);
        }
        if(test !=1) cout<<endl;
            cout<<representatives.size()<<endl;
        representatives.clear();
        conver_node.clear();
        taken.clear();
    }
    return 0;
}
