#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

int gcd(int a,int b)
{
    while(1)
    {
        int temp = a%b;

        if(temp ==0)
            return b;

        a = b;
        b =temp;

    }
}

int main()
{
    int N;
    //freopen("input.txt","r",stdin);
    int te = 0;
    while(scanf("%d",&N)&& N)
    {
        te++;
        int sum = 0;
        int issum = 0;

        for(int i = 0;i<N;i++)
        {
            int a;
            cin>>a;
            sum+=a;
        }
        if(sum<0)
        {
            issum = 1;
            sum=sum*(-1);
        }

        int ratioo = sum%N;
       sum = sum/N;

        int gcD = 1;
        if(ratioo!=0)
            gcD = gcd(ratioo,N);

        int size_sum = 0;
        int size_N = 0;
        int temp = (N/gcD);
        while(temp)
        {
            temp/=10;
            size_N++;
        }
        temp = sum;
        while(temp)
        {
            temp/=10;
            size_sum++;
        }

        if(issum)
        {
            size_sum+=2;
        }

        printf("Case %d:\n",te);
        if(ratioo!=0)
        {
            cout << setw(size_sum+size_N) <<(ratioo/gcD)<<endl;
            if(sum!=0)
            {

                if(issum)
                    cout<<"- "<<sum;
                else
                    cout<<sum;
            }
            else
            {
                if(issum)
                    cout<<"- ";
            }
            for(int i = 0;i<size_N;i++)
                cout<<"-";
            cout<<endl;
            for(int i = 0;i<size_sum;i++)
                cout<<" ";
            cout<<(N/gcD)<<endl;

        }
        else
        {
            if(issum)
                cout<<"- "<<sum<<endl;
            else
                cout<<sum<<endl;
        }
    }
}

