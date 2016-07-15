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
#include <algorithm>
#include <bitset>
#include <set>
#define MAX 100000000
using namespace std;

bool prime[MAX];
void seive()
{
    int i,j;
    prime[1] = false;
    prime[2] = true;
    for( i=3; i<=MAX; i+=2)
        prime[i]=true;
    for(i=4; i<=MAX; i+=2) prime[i]=false;
    for(i=3; i<=sqrt(MAX); i+=2)
    {
        if(prime[i]==true)
            for(j=i*i; j<MAX; j+=(2*i))
                prime[j]=false;
    }

}


int main()
{
    seive();
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int a,b;
        if(m<=3)
        {
            printf("%d is not the sum of two primes!\n",m);
        }
        else if(m%2==1)
        {
            if(prime[m-2])
            {
                a = 2;
                b= m - 2;
                printf("%d is the sum of %d and %d.\n",m,a,b);
            }
            else
                printf("%d is not the sum of two primes!\n",m);
        }
        else
        {
            if((m/2)%2==0)
            {
                a = (m/2)-1;
                b= (m/2) +1;
                int c= 0;
                for(;;)
                {
                    if(prime[a] && prime[b])
                    {
                        c=1;
                        break;
                    }
                    else
                    {
                        a-=2;
                        b+=2;
                    }
                    if(a<1 || b>m)
                    {
                        break;
                    }
                }
                if(c==1)
                    printf("%d is the sum of %d and %d.\n",m,a,b);
                else
                    printf("%d is not the sum of two primes!\n",m);
            }
            else
            {
                a = (m/2)-2;
                b= (m/2) +2;
                int c= 0;
                for(;;)
                {
                    if(prime[a] && prime[b])
                    {
                        c=1;
                        break;
                    }
                    else
                    {
                        a-=2;
                        b+=2;
                    }
                    if(a<1 || b>m)
                    {
                        break;
                    }
                }
                if(c==1)
                    printf("%d is the sum of %d and %d.\n",m,a,b);
                else
                    printf("%d is not the sum of two primes!\n",m);
            }
        }
    }
    return 0;
}
