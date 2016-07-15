#include <bits/stdc++.h>

using namespace std;

int main()
{
    int te;
    int a,b;
    cin>>te;
    getchar();
    stack<char>sk;
    string s;
    for(int t = 0;t<te;t++)
    {
        while(!sk.empty())
            sk.pop();

        getline(cin,s);

        bool flag = true;

        for(int i  =0;i<s.size();i++)
        {

            if(s[i]=='(' || s[i]=='[')
                sk.push(s[i]);
            else
            {
                if(sk.empty())
                {
                    flag = false;
                    break;
                }

                if(s[i]==')'  && sk.top()=='(')
                {
                    sk.pop();
                }
                else if(s[i]==']' && sk.top()=='[')
                {
                    sk.pop();
                }

                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag && sk.empty())
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }

}

