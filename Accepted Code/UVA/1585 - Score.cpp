#include<bits/stdc++.h>

using namespace std;

int main()
{
    int te;
    cin>>te;
    string s;
    for(int t = 0 ; t< te ;t++ )
    {
        cin>>s;
        int sum = 0  ;
        int track = 0 ;
        for(int i = 0 ; i< s.size() ; i++ )
        {
            if(s[i]=='O')
            {
                track ++ ;
                sum+=track;
            }
            else
                track = 0;
        }
        cout<<sum<<endl;
    }
}

