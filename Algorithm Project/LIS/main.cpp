#include <iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int lis_seqence[100];
int L[100];
int I[100];
int inf = 50000000;

int LIS(int &n)
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
    cout<<"maximum length is "<<maxLength<<endl;
    return maxLength;
}

int LIS_NlogK(int &n)
{
    I[0] = -inf;
    L[0] = 0;
    for(int i=1;i<=n;i++)
    {
        I[i] = inf;
        L[i] = 0;
    }
    int LisLength = 0;
    for(int i=0;i<n;i++)
    {
        int low,high,mid;
        low =0;
        high = LisLength;

        while(low<=high)
        {
            mid = (low+high)/2;
            if(I[mid]<lis_seqence[i])
                low = mid+1;
            else
                high = mid -1;
        }
        I[low] = lis_seqence[i];
        L[i] = low;
        if(LisLength <low)
            LisLength = low;
    }
    cout<<LisLength<<endl;
    return LisLength;
}
void LIS_find_sequence(int &maxLength,int &n)
{
    vector<int>v;
    int i;
    for(i=0;i<n;i++)
        if(maxLength==L[i])
            break;

    v.push_back(lis_seqence[i]);
    for(int j=i-1;j>=0;j--)
    {
        if((L[i]-L[j])==1 && lis_seqence[j]<lis_seqence[i])
        {
            v.push_back(lis_seqence[j]);
            i=j;
        }
    }
    cout<<"The lis sequence is "<<endl;
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<ends;
    cout<<endl;

}
int main()
{
    int a;
    //freopen("input.txt","r",stdin);
    cin>>a;
    for(int i=0;i<a;i++) cin>>lis_seqence[i];
    //int maximum=LIS(a);
    int maximum = LIS_NlogK(a);
    LIS_find_sequence(maximum,a);
    return 0;
}
