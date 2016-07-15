#include<iostream>
using namespace std;
int main()
{
    long long a,b,c;
    int i,j,k,l;
    for(;;)
    {
        cin>>a>>b;
        int count=0,m,n,x=0;
        if(a==0 && b==0) break;
        for(;;)
        {
            m=a%10+x;
            n=b%10;
            if(m+n>=10)
            {
                count++;
                x=1;
            }
            else x=0;
            a=a/10;
            b=b/10;
            if(a==0 && b==0) break;
        }
        if(count==0)
            cout<<"No carry operation."<<endl;
        else if(count==1)
            cout<<count<<" carry operation."<<endl;
        else
            cout<<count<<" carry operations."<<endl;
    }
    return 0;
}
