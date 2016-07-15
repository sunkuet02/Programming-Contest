#include<bits/stdc++.h>

using namespace std;

long long int F[2][2];
long long int M[2][2] = {{1,1} , {1,0} };
long long int mod;
void multiply(long long int FF[2][2],long long int M[2][2])
{
    long long int a = FF[0][0]*M[0][0] + FF[0][1]*M[1][0] ;
    long long int b = FF[0][0]*M[0][1] + FF[0][1]*M[1][1] ;
   long long  int c = FF[1][0]*M[0][0] + FF[1][1]*M[1][0] ;
   long long  int d = FF[1][0]*M[0][1] + FF[1][1]*M[1][1] ;
    F[0][0] = a%mod;
    F[0][1] = b%mod;
    F[1][0] = c%mod;
    F[1][1] = d%mod;
}

void power(int n)
{
    if(n==0 || n==1)
        return;
    power(n/2);
    multiply(F,F);

    if(n%2==1)
        multiply(F,M);
}

int fib(int n)
{
        F[0][0] = 1;
        F[0][1] = 1;
        F[1][0] = 1;
        F[1][1] = 0;
    if(n<=0)
        return 0;
    power(n-1);
}



int main()
{
    //freopen("input.txt","r",stdin);
     int m,n;
    while(scanf("%d %d",&n , &m)!=EOF)
    {
        mod = pow(2,m);
        //cout<<mod<<endl;

        if(n==0)
        {
            printf("0\n");
            continue;
        }
        else if(n==1 || n==2)
        {
            printf("1\n");
            continue;
        }

        fib(n-1);
        //cout<<F[0][0] + F[0][1]<<endl;
        printf("%d\n",(F[0][0] + F[0][1])%mod);
    }
    return 0;
}
