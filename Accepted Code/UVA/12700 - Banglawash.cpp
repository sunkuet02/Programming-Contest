#include <bits/stdc++.h>

using namespace std;

int main()
{
    int te;
    int a;
    cin>>te;
    for(int t =1;t<=te;t++)
    {

        cin>>a;
        string s;
        cin>>s;
        int  b = 0;
        int w = 0;
        a = 0;
        int tie = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='B')
                b++;
            else if(s[i]=='W')
                w++;
            else if(s[i]=='A')
                a++;
            else if(s[i]=='T')
                tie ++;
        }
        printf("Case %d: ",t);
        if(a==s.size())
            cout<<"ABANDONED"<<endl;
        else if(b==w)
            cout<<"DRAW "<<b<<" "<<tie<<endl;
        else if( (b+ a)==s.size())
            cout<<"BANGLAWASH"<<endl;
        else if( (w +a)==s.size())
            cout<<"WHITEWASH"<<endl;
        else if(b>w)
            cout<<"BANGLADESH "<<b<<" - "<<w<<endl;
        else if(w>b)
            cout<<"WWW "<<w<<" - "<<b<<endl;
    }

}

