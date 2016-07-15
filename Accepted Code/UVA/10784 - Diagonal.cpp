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
using namespace std;

int main()
{
    long long N;
    int j=0;
    while(scanf("%lld",&N)&& N)
    {
        j++;
        long long n = (3+sqrt(9+(4*2*N)))/2;
        long long ans = n*(n-3)/2;
        if(ans<N)
            n=n+1;
        cout<<"Case "<<j<<": "<<n<<endl;
    }
    return 0;
}
