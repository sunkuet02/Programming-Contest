#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    map<char,int>mp;
    map<char,int>::iterator it;
    long j,k,m,q,value;
    long long sum;
    long p,i;
    char ch;
    cin>>q;
    for(k=1;k<=q;k++)
    {
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>ch>>value;
            mp.insert(pair<char,int>(ch,value));
        }
        string line;
        cin>>p;
        getchar();
        sum=0;
        for(i=1;i<=p;i++)
        {
            getline (cin, line);

            for(j=0;line[j]!='\0';j++)
            {
                it=mp.find(line[j]);
                if(it!=mp.end())
                {
                    sum+=it->second;
                }
                else sum+=0;
            }
        }
        double u;
        u=(double)sum/100.0;
        printf("%.2lf$\n", u);
        mp.clear();
    }
    return 0;
}

