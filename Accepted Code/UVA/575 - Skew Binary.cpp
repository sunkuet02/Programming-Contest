#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    string st;
    int i,j,a,m;
    long num;
    while(1)
    {
        cin>>st;
        num=0;
        j=1;
        for(i=st.size()-1;i>=0;i--)
        {
            a=(st[i]-48)*(pow(2,j++)-1);
            num+=a;
        }
        if(num==0) break;
        cout<<num<<endl;
    }
    return 0;
}
