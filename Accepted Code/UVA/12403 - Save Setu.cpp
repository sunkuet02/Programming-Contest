#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    long int ammount=0,donate;
    int i,j,m;
    string st;
    cin>>m;
    getchar();
    for(i=1;i<=m;i++)
    {
        cin>>st;
        if(st=="donate")
        {
            cin>>donate;
            getchar();
            ammount+=donate;
        }
        else if(st=="report")
        {
            cout<<ammount<<endl;
        }
    }
}
