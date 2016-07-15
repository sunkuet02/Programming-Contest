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
    vector< vector<int> >ma;
    vector<int>sum,v1,v2;
    v1.push_back(0);
    v2.push_back(1);
    for(int i=1; i<=1005; i++)
    {
        int carry=0;
        int n=v1.size()-1;
        int m=v2.size()-1;
        while(n!=-1)
        {
            int a=carry+v2[m]+v1[n];
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
            int a=carry+v2[m];
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
        ma.push_back(sum);
        v1=v2;
        v2=sum;
        sum.clear();
    }
    int M;
    while(scanf("%d",&M)!=EOF)
    {
        sum  = ma[M];
        for(int i=0;i<sum.size();i++)
            cout<<sum[i];
        cout<<endl;
    }
    sum.clear();
    v1.clear();
    v2.clear();
    for(int i=0;i<ma.size();i++)
    {
        ma[i].clear();
    }
    return 0;
}
