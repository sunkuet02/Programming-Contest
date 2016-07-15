#include<bits/stdc++.h>
#define Max 1005
using namespace std;

int main()
{
    //freopen("input.txt" , "r" ,stdin);

    map<string , string> mp ;
    map<string , string> ::iterator it;
    string s , temp ;
    while(cin>>s)
    {
        if(s=="XXXXXX")
            break;
        temp = s;
        sort(temp.begin() , temp.end());
        mp[s] =temp ;
    }
    while(cin>>s)
    {
        bool cn = false;
        if(s=="XXXXXX")
            break;
        temp = s;
        sort(temp.begin() , temp.end());
        for(it = mp.begin()   ; it!= mp.end() ; it++)
        {
            if(it->second == temp)
            {
                cout<<it->first<<endl;
                cn = true;
            }
        }
        if(!cn)
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }


}
