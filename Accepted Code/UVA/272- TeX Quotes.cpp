#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    string st;
    int j=0;
    while((getline(cin,st)))
    {

        char ch;
        for(int i=0;i<st.size();i++)
        {
            if(st[i]=='"')
            {
                j++;
                if(j%2==1)
                {
                    cout<<"``";
                }
                else
                {
                    cout<<"''";

                }
            }
            else
               cout<<st[i];
        }
        cout<<endl;
    }
    return 0;
}
