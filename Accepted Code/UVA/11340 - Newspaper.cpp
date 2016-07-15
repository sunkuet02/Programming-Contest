#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int i,a,sum;
    cin>>a;
    for(i=1;i<=a;i++)
    {
        int j,m,b;
        char z;
        map<char,int>news;
        cin>>m;
        for(j=1;j<=m;j++)
        {
            cin>>z>>b;
            news[z]=b;
        }
        int k,n;
        string st;
        cin>>n;
        for(k=1;k<=n;k++)
        {
            getline(cin,st);
            for(int l=0;st[l]!='\0';l++)
            {
                sum+=news.find(st[l])->first;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
