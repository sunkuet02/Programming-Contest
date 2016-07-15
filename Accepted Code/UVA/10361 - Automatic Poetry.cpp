#include <bits/stdc++.h>

using namespace std;


int main()
{
    //freopen("input.txt","r",stdin);
    int test ;
    cin>>test;
    getchar();
    while(test--)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);

        string temp1,temp2,temp3,temp4;

        int i = 0;
        while(s1[i]!='<')
        {
            cout<<s1[i];
            i++;
        }
        i++;
        while(s1[i]!='>')
        {
            cout<<s1[i];
            temp1.push_back(s1[i]);
            i++;
        }
        i++;
        while(s1[i]!='<')
        {
            cout<<s1[i];
            temp2.push_back(s1[i]);
            i++;
        }
        i++;
        while(s1[i]!='>')
        {
            cout<<s1[i];
            temp3.push_back(s1[i]);
            i++;
        }
        i++;
        while(s1[i]!='\0')
        {
            cout<<s1[i];
            temp4.push_back(s1[i]);
            i++;
        }
        cout<<endl;
        i = 0;
        while(s2[i]!='.' || s2[i+1]!='.' || s2[i+2]!='.')
        {
            cout<<s2[i];
            i++;
        }
        cout<<temp3<<temp2<<temp1<<temp4<<endl;

        temp1.clear();
        temp2.clear();
        temp3.clear();
        temp4.clear();

    }


    return 0;
}

