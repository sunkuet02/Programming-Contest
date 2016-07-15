#include<bits/stdc++.h>

using namespace std;


int main()
{
    int test;
    cin>>test;
    for(int t = 1; t<= test; t++ )
    {
        int n,x,k;
        cin>>n>>k>>x;
        
        int sumUpToN = (n*(n+1))/2;
        
        int sumUpToXplusK = ((x+k-1)*(x+k))/2;
        
        int sumUpToX = ((x-1)*(x))/2;
        printf("Case %d: %d\n",t,sumUpToN-sumUpToXplusK + sumUpToX);
    }
    return 0;
}