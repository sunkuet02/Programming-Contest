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
using namespace std;
struct node
{
    int a,b;
};
long sieve_size;
bitset<20000010>bs;
vector<int> primes;
void seive(long upper)
{
    sieve_size = upper + 1;
    bs.set();
    bs[0]=0;
    bs[1]=0;
    for(long i=4;i<sieve_size;i+=2)
        bs[i]=0;
    for(int i=3;i<sqrt(sieve_size);i+=2)
        if(bs[i]==1)
            for(int j=i*i;j<sieve_size;j+=(2*i))
                bs[j]=0;
}
int main()
{
    seive(20000000);
    int m=3,n;
    primes.push_back(0);
    for(int i=5;i<20000000;i+=2)
    {
        if(bs[i]==1)
        {
            if((i-m)==2)
            {
                primes.push_back(m);
                primes.push_back(i);
            }
            m=i;
        }
    }
    int A;
    while(scanf("%d",&A)!=EOF)
    {
        cout<<"("<<primes[2*A-1]<<", "<<primes[2*A]<<")"<<endl;
    }
    primes.clear();
    return 0;
}
