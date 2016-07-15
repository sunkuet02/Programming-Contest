
/************* A program for summing 2 digit of infinit range***************/

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
    while(1)
    {
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++)
            v1.push_back(s1[i]-48);
        for(int i=0;i<s2.size();i++)
            v2.push_back(s2[i]-48);
        if(v2.size()>v1.size())          //SWAPING FOR CONSUMING WORK
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
        //reverse(sum.begin(),sum.end());
        int p=sum.size()-1;
        while(sum[p]==0)     // for removing
        {                    // trailing
            p--;             //zero(0)
        }
        for(int i=p;i>=0;i--) cout<<sum[i];
        cout<<endl;
        v1.clear();
        v2.clear();
        v3.clear();
        sum.clear();

    }
    return 0;
}
