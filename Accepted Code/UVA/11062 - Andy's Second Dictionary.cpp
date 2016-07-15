#include<bits/stdc++.h>


using namespace std;

int main()
{
    string s;
    set<string>v;
    set<string> ::iterator it;
    string temp = "" ;
    while(getline(cin,s))
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        for(int i = 0 ; i< s.size()  ; i ++ )
        {
            if((s[i]>=97 && s[i]<=122) || s[i]=='-')
            {
                if(i==s.size()-1 && s[i]=='-')
                    continue;
                temp.push_back(s[i]);
            }
            else
            {
                if(temp.size()!=0)
                v.insert(temp);
                temp = "";
            }
        }

        if(s.size()!=0)
        if(s[s.size()-1]!='-' && temp.size()!=0)
        {
            v.insert(temp);
            temp = "";
        }
        if(s.size()==0 && temp.size()!= 0 )
        {
            v.insert(temp);
            temp = "";
        }
    }
    if(temp.size()!= 0 )
        {
            v.insert(temp);
            temp = "";
        }

    for(it = v.begin() ; it != v.end() ; it++  )
        cout<<*it<<endl;
}

