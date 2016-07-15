#include<bits/stdc++.h>

using namespace std;

int F[2][2];
int M[2][2] = {{1,1} , {1,0} };
int mod;
void multiply(int F[2][2],int M[2][2])
{
    int a = F[0][0]*M[0][0] + F[0][1]*M[1][0] ;
    int b = F[0][0]*M[0][1] + F[0][1]*M[1][1] ;
    int c = F[1][0]*M[0][0] + F[1][1]*M[1][0] ;
    int d = F[1][0]*M[0][1] + F[1][1]*M[1][1] ;
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
    if(n==0)
        return 0;
    power(n-1);
}



int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int t =1; t<= n ; t++ )
    {
        int a,b,n,m;
        scanf("%d %d %d %d",&a,&b,&n,&m);
        mod = 1;
        for(int i = 1; i<=m; i++)
            mod*=10;

        fib(n);


        printf("Case %d: %d\n",t,(F[0][0]*b + F[0][1]*a)%mod);
    }
    return 0;
}

