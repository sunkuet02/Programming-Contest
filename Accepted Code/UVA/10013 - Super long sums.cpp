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

    vector<int>v1,v2,v3,sum;
    int N;
    cin>>N;
    for(int test = 1; test<=N; test++)
    {
        int M;
        cin>>M;
        for(int test2=0; test2<M; test2++)
        {
            int a,b;
            cin>>a>>b;
            v1.push_back(a);
            v2.push_back(b);
        }
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
        reverse(sum.begin(),sum.end());
        int p;
        int i=0;
        while(sum[i]==0)
        {
            i++;
        }
        p=i;
        if(p==sum.size()) cout<<0;
        else
            for(int i=p; i<sum.size(); i++) cout<<sum[i];
        cout<<endl;
        if(test!=N)
            cout<<endl;
        sum.clear();
        v1.clear();
        v2.clear();
    }
    return 0;
}
