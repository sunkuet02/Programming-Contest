/******************Accepted***************/

#include<iostream>
#include<set>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int L[10000];
int arr[10000];
int LIS(int m)
{
    for(int i=0; i<=m; i++)
        L[i]=1;
    for(int i=0; i<m; i++)
        for(int j=i+1; j<m; j++)
            if(arr[i]>=arr[j])
                if(L[j]<L[i]+1)
                    L[j]=L[i]+1;
    int maxx=0;
    for(int i=0; i<m; i++)
        if(L[i]>maxx)
            maxx=L[i];
    return maxx;
}
int main()
{
    int i,k=0;
    int a,b;
    int c=0;
    while(1)
    {
        i=0;
        c++;
        if(k!=0)
        {

            cin>>a;
            if(a==-1 && b==-1) break;
            else arr[i++]=a;
            cout<<endl;
        }
        while(cin>>b && b!=-1)
        {
            arr[i++]=b;
        }
        int m=i;
        cout<<"Test #"<< c <<":"<<endl;
        cout<<"  maximum possible interceptions: "<<LIS(m)<<endl;
        k++;
    }
    return 0;
}
