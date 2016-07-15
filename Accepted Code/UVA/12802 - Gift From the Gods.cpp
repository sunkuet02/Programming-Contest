/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>

#define scan(a) scanf("%lld",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);

#define LL long long int
#define MAX 1000005
using namespace std;
bool prime[MAX];
void seive()
{
    for(int i=2;i<=MAX;i++)
        prime[i]=true;
    for(int i=4;i<=MAX;i+=2) prime[i]=false;
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i]==true)
        for(int j=i*i;j<MAX;j+=(2*i))
            prime[j]=false;
    }
}

bool ispallindrome(int n)
{
    vector<int>v;
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    int i = 0 ;
    int j = v.size()-1;
    while(i<j)
    {
        if(v[i]!=v[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    //READ();
    seive();
    long long int n;
    while(scan(n)!=EOF )
    {

        printf("%lld\n",n*2);
        int a = int(n);
        if(prime[a])
        {
            if(ispallindrome(a))
                break;
        }

    }

}

