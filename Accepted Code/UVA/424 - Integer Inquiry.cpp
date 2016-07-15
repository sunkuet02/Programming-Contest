#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int j=0;
    vector<int>sum,v1,v2,v3;
    while(1)
    {
        getline(cin,s);
        if(s.size()==1 && s[0]=='0')
            break;
        if(j==0)
            for(int i=0; i<s.size(); i++)
                sum.push_back(s[i]-48);
        else
        {
            for(int i=0; i<s.size(); i++)
                v1.push_back(s[i]-48);

            v2=sum;
            sum.clear();
            if(v2.size()>v1.size())
            {
                v3=v1;
                v1=v2;
                v2=v3;
            }
            int carry=0;
            int m=v1.size()-1;
            int n=v2.size()-1;
            while(n!=-1)
            {
                int a=carry+v1[m]+v2[n];
                if(a<10)
                {
                    carry=0;
                    sum.push_back(a);
                }
                else
                {
                    carry=1;
                    sum.push_back(a%10);
                }
                m--;
                n--;
            }
            while(m!=-1)
            {
                int a=carry+v1[m];
                if(a<10)
                {
                    carry=0;
                    sum.push_back(a);
                }
                else
                {
                    carry=1;
                    sum.push_back(a%10);
                }
                m--;
                n--;
            }
            if(carry==1)
                sum.push_back(1);
            reverse(sum.begin(),sum.end());
        }
        j++;
        v1.clear();
    }
    int p;
    int i=0;

    while(sum[i]==0)
        i++;
    p=i;
    if(p==sum.size()) cout<<0;
    else
        for(int i=p; i<sum.size(); i++) cout<<sum[i];
    cout<<endl;
    return 0;
}
