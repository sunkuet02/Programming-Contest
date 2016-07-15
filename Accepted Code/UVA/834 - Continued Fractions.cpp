#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,a,c,b;
    for(;;)
    {
        cin>>a>>b;
        c=a/b;
        cout<<"["<<c<<";";
        c=a%b;
        a=b;
        b=c;
        for(;;)
        {
            c=a/b;
            cout<<c;
            c=a%b;
            a=b;
            b=a;
            if(c==0)
            {
                cout<<"]";
                break;
            }
            else
                cout<<",";
        }
        cout<<endl;
    }
}
