#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#define Max 1000000
using namespace std;

bool prime[Max];
void seive()
{
    for(int i = 2; i<=Max; i++)
        prime[i] = true;
    for(int i=4; i<=Max; i+=2)
        prime[i] = false;
    for(int i = 3; i<=sqrt(Max); i+=2)
        if(prime[i])
            for(int j = i*i; j<=Max; j+=(2*i))
                prime[j] = false;
}
int main()
{
    int A;
    seive();
    while(scanf("%d",&A)&& A)
    {
        int m,n;
        if(A==4)
        {
            m=2;
            n=2;
        }
        else if(A%2==0)
        {
            m=A-3;
            n=3;
            for(;;)
            {
                if((prime[m] && prime[n]))
                {
                    break;
                }
                m-=2;
                n+=2;
                if(n>m)
                {
                    m=0;
                    n=0;
                    break;
                }

            }
        }
        else
        {
            m=A-2;
            n=2;
            if(prime[m]&& prime[n])
            {
                m=m;
                n=n;
            }
            else
            {
                m=0;
                n=0;
            }
        }
        printf("%d:\n",A);
        if(m==0 && n==0)
            printf("NO WAY!\n");
        else
            printf("%d+%d\n",n,m);
    }

    return 0;
}
