#include<bits/stdc++.h>

using namespace std;

bool is400(string s)
{
    int a =0;
    for(int i = 0;i<s.size();i++)
    {
        a = a*10 + ( s[i] - 48);

        if(a>=400)
            a = a%400;

    }

    if(a==0)
        return true;
    else
        return false;


}
bool is100(string s)
{
    int a = 0;
    for(int i = 0;i<s.size();i++)
    {
        a = a*10 + s[i] - 48;
        if(a>=100)
            a = a%100;

    }
    if(a==0)
        return true;
    else
        return false;
}
bool is4(string s)
{
    int a = 0;
    for(int i = 0;i<s.size();i++)
    {
        a = a*10 + s[i] - 48;
        if(a>=4)
            a = a%4;

    }
    if(a==0)
        return true;
    else
        return false;
}
bool is15(string s)
{
    int a = 0;
    for(int i = 0;i<s.size();i++)
    {
        a = a*10 + s[i] - 48;
        if(a>=15)
            a = a%15;

    }
    if(a==0)
        return true;
    else
        return false;
}
bool is55(string s)
{
    int a = 0;
    for(int i = 0;i<s.size();i++)
    {
        a = a*10 + s[i] - 48;
        if(a>=55)
            a = a%55;

    }
    if(a==0)
        return true;
    else
        return false;
}

int main()
{

    string m;
    int t  = 0;
    while(cin>>m)
    {
        if(t!=0)
            cout<<endl;
        t++;
        bool flag = false;
        if((is4(m)&& !is100(m)) || is400(m))
        {
            printf("This is leap year.\n");
            flag = true;
        }
        if(is15(m))
        {
            printf("This is huluculu festival year.\n");
            flag  = true;
        }
        if(((is4(m)&& !is100(m)) || is400(m)) && is55(m))
        {
            printf("This is bulukulu festival year.\n");
            flag = true;
        }

        if(!flag )
        {
            printf("This is an ordinary year.\n");
        }
    }
}
