#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace  std;
int disjoint[5005];
int find_representative(int a)
{
    if(disjoint[a]==a) return a;
    else
        return disjoint[a]=find_representative(disjoint[a]);
}
int main()
{
    map<string , int>convert_creature;
    string creature;
    int c,r;
    int highest[5005];
    while(1)
    {
        cin>>c>>r;
        if(c==0 && r==0) break;
        for(int i=1;i<=c;i++)
        {
            cin>>creature;
            convert_creature[creature]=i;
            disjoint[i]=i;
            highest[i] = 1;
        }
        string creature1,creature2;
        int node1, node2,n=0;
        for(int i=1;i<=r;i++)
        {
            cin>>creature1>>creature2;
            int a=find_representative(convert_creature.find(creature1)->second);
            int b=find_representative(convert_creature.find(creature2)->second);
            if(a!=b)
            {
                if(highest[a]>=highest[b])
                {
                    disjoint[b]=a;
                    highest[a]+=highest[b];
                }
                else
                {
                    disjoint[a] = b;
                    highest[b]+=highest[a];
                }
            }
        }
        int total =0;
        for(int i=1;i<=c;i++)
            if(total<highest[i])
               total = highest[i];
        cout<<total<<endl;
        convert_creature.clear();
    }
    return 0;
}
