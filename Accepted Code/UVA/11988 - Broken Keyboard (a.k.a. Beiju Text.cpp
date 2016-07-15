#include<bits/stdc++.h>
#define Max 1005
using namespace std;

int main()
{
    string s;
    list<char>lis;
    list<char>::iterator it;
    while(cin>>s)
    {
        bool flag = true;
        string temp;
        for(int i = 0 ; i< s.size() ; i++ )
        {
            if(s[i]=='[')
            {
                for(int j = temp.size() - 1 ; j>=0  ; j-- )
                    lis.push_front(temp[j]);
                temp.clear();
                flag = false;
            }
            else if(s[i]==']')
            {
                for(int j = temp.size() - 1 ; j>=0  ; j-- )
                    lis.push_front(temp[j]);
                temp.clear();
                flag = true;
            }
            else
            {
                if(flag)
                {


                    lis.push_back(s[i]);

                }
                else
                {
                    temp.push_back(s[i]);
                }
            }
        }
        if(temp.size()!=0)
        {
            for(int j = temp.size() - 1 ; j>=0  ; j-- )
                lis.push_front(temp[j]);
            temp.clear();
        }
        for(it = lis.begin() ; it!=lis.end() ; it++)
            cout<<*it;
        cout<<endl;
        lis.clear();

    }
}

