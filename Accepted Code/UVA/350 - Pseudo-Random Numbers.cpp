#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,z,l,m,k=0;
    int a,b,c;
    while(1)
    {
        k++;
        cin>>z>>i>>m>>l;
        if(z==0 && i==0 && m==0 && l==0) break;
        a=(z*l+i)%m;
        c=a;
        for(j=1;j;j++)
        {
            b=(z*a+i)%m;
            if(b==c)
            {
                cout<<"Case "<<k<<": "<<j<<endl;
                break;
            }
            a=b;
        }
    }
    return 0;
}
