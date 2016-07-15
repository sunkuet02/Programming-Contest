/*************Accepted***************/

#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    string s,s1,s2;
    int maxx=0;
    while(1)
    {
        cin>>s;
        if(s=="E-N-D") break;
        int countt=0,j=0;
        for(int i=j; i<s.size(); i++)
        {
            if((s[i]>=65 && s[i]<=90) ||(s[i]>=97 && s[i]<=122)|| s[i]=='-')
            {
                countt++;
                s1.push_back(s[i]);
            }
            else
            {
                if(countt>maxx)
                {
                    maxx=countt;
                    s2=s1;
                    s1.clear();
                    countt=0;
                }

            }
        }
        if(countt>maxx)
        {
            maxx=countt;
            s2=s1;
            s1.clear();
        }
        s1.clear();
    }
    for(int i=0; i<s2.size(); i++)
    {
        if(s2[i]>=65 && s2[i]<=90)
            s2[i]=s2[i]+32;
    }
    cout<<s2<<endl;
    return 0;

}
