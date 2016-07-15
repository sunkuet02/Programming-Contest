#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
bool digit[6000]= {0};
void equet()
{
    int countt=0,j;
    set<int>s;
    for(int i=0; i<=5000; i++)
    {
        int m=i;
        for(j=1; j; j++)
        {
            s.insert(m%10);
            m=m/10;
            if(m==0) break;
        }
        if(j==s.size()) digit[i]=1;
        s.clear();
    }
}
int main()
{
    int a,b;
    equet();
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int countt=0;
        for(int i=a;i<=b;i++)
            if(digit[i])
                countt++;
        cout<<countt<<endl;
    }
    return 0;
}
