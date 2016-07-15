#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<char>v;
    string s;

    while(cin>>s)
    {
        if(s=="#")
            break;
        int c=0;
        for(int i = 0;i<s.size()-1;i++)
        {
            if(s[i]<s[i+1])
            {
                c = 1 ;
                break;
            }
        }
        if(c==0)
        {
            cout<<"No Successor"<<endl;
            continue;
        }
        for(int i =0;i<s.size();i++)
            v.push_back(s[i]);
        next_permutation(v.begin(),v.end());
        for(int i = 0;i<v.size();i++)
            cout<<v[i];
        cout<<endl;
        v.clear();
    }
}

