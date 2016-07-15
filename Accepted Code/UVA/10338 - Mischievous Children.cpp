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
#include <bitset>
#include <set>
using namespace std;

int main()
{
    long long int fact[25];
    long long int  sum=1;
    for(int i=1;i<20;i++)
    {
        sum = sum*i;
        fact[i]=sum;
    }
    string s;
    int N;
    set<char>charact;
    set<char>::iterator it;
    cin>>N;
    for(int test  = 1;test<=N;test++)
    {
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            charact.insert(s[i]);
        }
        sum = 1;
        for(it=charact.begin();it!=charact.end();it++)
        {
            int j=0;
            for(int i=0;i<s.size();i++)
                if((*it)==s[i])
                    j++;
            sum = sum*fact[j];
        }
        long long int result =(fact[s.size()])/sum;
        cout<<"Data set "<<test<<": ";
        cout<<result<<endl;
        charact.clear();
    }
    return 0;
}
