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
int lis_seqence[100010];
int lis_value[100100];
int L[100010];
int LIS_increasing(int &n)
{
    for(int i=0;i<n;i++)
        L[i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(lis_seqence[i]<lis_seqence[j])
            {
                if(L[j]<L[i]+1)
                L[j]=L[i]+1;
            }
        }
    }
    int maxLength=0;
    for(int i=0;i<n;i++)
        if(maxLength<L[i])
            maxLength=L[i];
    int i;
    for(i=0;i<n;i++)
        if(maxLength==L[i])
            break;

    int sum =0;
    sum+=lis_value[i];
    for(int j=i-1;j>=0;j--)
    {
        if((L[i]-L[j])==1 && lis_seqence[j]<lis_seqence[i])
        {
            sum+=lis_value[j];
            i=j;
        }
    }
    return sum;
}

int LIS_decreasing(int &n)
{
    for(int i=0;i<n;i++)
        L[i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(lis_seqence[i]>lis_seqence[j])
            {
                if(L[j]<L[i]+1)
                L[j]=L[i]+1;
            }
        }
    }
    int maxLength=0;
    for(int i=0;i<n;i++)
        if(maxLength<L[i])
            maxLength=L[i];
    int i;
    for(i=0;i<n;i++)
        if(maxLength==L[i])
            break;

    int sum =0;
    sum+=lis_value[i];
    for(int j=i-1;j>=0;j--)
    {
        if((L[i]-L[j])==1 && lis_seqence[j]>lis_seqence[i])
        {
            sum+=lis_value[j];
            i=j;
        }
    }
    return sum;
}
int main()
{
    int N;
    cin>>N;
    for(int test =1;test<=N;test++)
    {
        int M;
        cin>>M;
        for(int te = 0;te<M;te++)
            cin>>lis_seqence[te];
        for(int te = 0;te<M;te++)
            cin>>lis_value[te];
        int increasing = LIS_increasing(M);
        int decreasing = LIS_decreasing(M);
        if(decreasing>increasing)
            cout<<"Case "<<test<<". Decreasing ("<<decreasing<<"). Increasing ("<<increasing<<")."<<endl;
        else
            cout<<"Case "<<test<<". Increasing ("<<increasing<<"). Decreasing ("<<decreasing<<")."<<endl;
    }
    return 0;
}
