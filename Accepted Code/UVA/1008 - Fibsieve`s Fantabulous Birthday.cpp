#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long a,n;
    long x,y;
    int i,m,k;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>n;
        a=sqrt(n);
        if(a%2==0)
        {
            if(n==a*a)
            {
                x=a;
                y=1;
            }
            else if(a*a<n && n>=((a+1)*(a+1)-a))
            {
                x=(a+1)*(a+1)-n+1;
                y=a+1;
            }
            else if(a*a<n && n<=(a*a+a))
            {
                x=a+1;
                y=n-a*a;
            }
        }
        else
        {
            if(a*a==n)
            {
                x=1;
                y=a;
            }
            else if(n>a*a && n>=((a+1)*(a+1)-a))
            {
                x=a+1;
                y=(a+1)*(a+1)-n+1;
            }
            else if(n>a*a && n<=(a*a+a))
            {
                x=n-a*a;
                y=a+1;
            }
        }
        cout<<"Case "<<i<<": ";
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
