   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL long long int
#define mx 15
#define MAX 15
#define sz 10005
using namespace std;

LL fib[50], sum [50];
bool res[50];

void precal()
{
    fib[1] = 1;
    fib[2] = 1;
    sum[1] = 1;
    sum[2] = 2;
    for(int i = 3; i<=44; i++ )
    {
        fib[i] = fib[i-1] + fib[i-2];
        sum[i] = sum[i-1] + fib[i];
    }

}

void calculate(int n )
{
    if( !n) return ;
    if(n<3)
    {
        res[n] = true;
        return;
    }
    for(int i =1 ; ; i++ )
    {
        if(sum[i]>=n)
        {
            res[i] = true;
            return calculate(n  - sum[i-1] - 1);
        }
    }

}


int main()
{
    //READ();

    precal();
    int test;
    scan(test);
    for(int t = 1; t<= test ; t ++ )
    {
        memset(res, false, sizeof(res));

        int n;
        scan(n);
        calculate(n) ;
        bool is = false;
        printf("Case %d: ",t);
        for(int i = 45 ; i>=1; i--)
        {
            if(res[i])
            {
                printf("1");
                is = true;
            }
            else if(is)
                printf("0");
        }
        printf("\n");

    }

}

