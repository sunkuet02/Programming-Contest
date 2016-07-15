#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    map<string,string>princes;
    string st1,st2;
    int m,n;
    cin>>m;
    getchar();
    for(int i=1;i<=m;i++)
    {
        getline(cin,st1);
        getline(cin,st2);
        princes[st1]=st2;
    }
    cin>>n;
    getchar();
    string st3;
    for(int i=1;i<=n;i++)
    {
        getline(cin,st3);
        cout<<princes.find(st3)->second<<endl;
    }
    return 0;
}
