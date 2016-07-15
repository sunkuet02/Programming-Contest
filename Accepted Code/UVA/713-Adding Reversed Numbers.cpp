


#include<iostream>
#include<set>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2;
    vector<int >v1,v2,v3,sum;
    int c;
    cin>>c;
    for(int k=1;k<=c;k++)
    {
        cin>>s1>>s2;
        for(int i=s1.size()-1;i>=0;i--)
            v1.push_back(s1[i]-48);
        for(int i=s2.size()-1;i>=0;i--)
            v2.push_back(s2[i]-48);
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
        if(carry==1) sum.push_back(1);
        int p;
        int i=0;
        while(sum[i]==0)
        {
            i++;
        }
        p=i;
        if(p==sum.size()) cout<<0;
        else
        for(int i=p;i<sum.size();i++) cout<<sum[i];
        cout<<endl;
        v1.clear();
        v2.clear();
        v3.clear();
        sum.clear();

    }
    return 0;
}
