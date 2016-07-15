#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string st;
    int i,j,k,sign,x,l,m;
    int first,second,third;
    int count=0;
    while(cin>>st)
    {
        getchar();
        x=0;
        for(i=0;;i++)
            if(st[i]=='+' || st[i]=='-')
            {
                k=i;
                if(st[i]=='+') sign=1;
                else sign=2;
                for(int j=0;j<k;j++)
                {
                    x=x*10+st[j]-48;
                }
                first=x;
                x=0;
                break;
            }

        for(i=i+1;i;i++)
        if(st[i]=='=')
            {
                for(int j=k+1;j<i;j++)
                {
                    x=x*10+st[j]-48;
                }
                k=i;
                second=x;
                x=0;
                break;
            }

            if(st[i+1]=='?') continue;
            else
            for(int j=k+1;j<st.size();j++)
            {
                    x=x*10+st[j]-48;
            }
            third=x;
            x=0;
            if(sign==1)
            {
                if(first+second==third) count++;

            }
            else if(sign==2)
            {
                if(first-second==third) count++;

            }
    }
    cout<<count<<endl;
    return 0;
}
