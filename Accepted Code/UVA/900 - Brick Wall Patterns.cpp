#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int i,j,k,m,a;
    map<int , long long>mp;
    long long int f3,f1=0,f2=1;
    for(i=1;i<=51;i++)
    {
        f3=f1+f2;
        mp[i]=f3;
        f1=f2;
        f2=f3;
    }
    for(;;)
    {
        cin>>a;
        if(a==0) break;
        cout<<mp.find(a)->second<<endl;
    }
    return 0;
}
