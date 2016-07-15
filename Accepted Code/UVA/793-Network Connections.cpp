#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#include<set>
#include<string>
using namespace std;
int network[5000]={0};
int find_representative(int a)
{
    if(network[a]==a) return a;
    return network[a]=find_representative(network[a]);
}
int main()
{
    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        int high_node;
        cin>>high_node;
        for(int j=1;j<=high_node;j++)
        {
            network[j]=j;
        }
        int n1,n2;
        n1=0;
        n2=0;
        char ch;
        getchar();
        int *qit,*pit;
        while((ch = getchar ()) && isalpha (ch))
        {
            int ci,cj;
            cin>>ci>>cj;
            if(ch=='c')
            {
                int a=find_representative(ci);
                int b=find_representative(cj);
                if(a!=b)
                {
                    network[a]=b;
                }
            }
            else if(ch=='q')
            {
                for(int j=1;j<=high_node;j++)
                {
                    int a=find_representative(j);
                    network[j]=a;
                }
                if(network[ci]==network[cj])
                    n1++;
                else n2++;
            }
            getchar();
        }
        if(i!=1) cout<<endl;
        cout<<n1<<","<<n2<<endl;
    }
    return 0;
}
