#include<bits/stdc++.h>

using namespace std;

int main()
{
    int te;
    cin>>te;

    string s;
    for(int t = 1;t<=te;t++)
    {
        int m;
        cin>>m;
        getchar();
        printf("Case %d:\n",t);
        for(int i = 0;i<m;i++)
        {
            getline(cin,s);
            for(int j = 0;j<s.size();j++)
            {
                if(s[j]==' ')
                {
                    if(s[j+1]!=' ')
                    {
                        cout<<s[j];
                        continue;
                    }
                }
                else
                cout<<s[j];

            }
            cout<<endl;
        }
        if(t!=te)
            cout<<endl;

    }
}
