#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int i,j,m,a,b,c,d,p,q,r,s;
    long a1,b1,c1,d1;
    int sum1,sum2,sum3,sum4;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        sum1=sum2=sum3=sum4=0;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%ld.%ld.%ld.%ld",&a1,&b1,&c1,&d1);
        for(j=0;j<=7;j++)
        {
            p=a1%10;
            p=p*pow(2,j);
            sum1+=p;
            a1=a1/10;
            q=b1%10;
            q=q*pow(2,j);
            sum2+=q;
            b1=b1/10;
            r=c1%10;
            r=r*pow(2,j);
            sum3+=r;
            c1=c1/10;
            s=d1%10;
            s=s*pow(2,j);
            sum4+=s;
            d1=d1/10;
        }
        if(a==sum1 && b==sum2 && c==sum3 && d==sum4)
            cout<<"Case "<<i<<": Yes"<<endl;
        else
            cout<<"Case "<<i<<": No"<<endl;
    }
    return 0;
}
