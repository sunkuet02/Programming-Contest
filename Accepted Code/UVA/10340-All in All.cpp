#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    string s,t;
    while(cin>>s)
    {
        cin>>t;
        int i=0;
        int j=0;
        int count=0;
        while(s[i]!='\0' && t[j]!='\0')
        {
            if(s[i]==t[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
            if(t[j]=='\0') break;
        }
        if(count==s.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
