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
int Merge(int low,int mid , int high);
int L[1000],R[1000];
int A[60000];
int countt;
int MergeSort(int low,int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }

}
int Merge(int low,int mid , int high)
{
    int l1 = mid - low +1;
    int l2 = high - mid;
    for(int i=0; i<l1; i++)
        L[i] = A[low +i];
    for(int j=1; j<=l2; j++)
        R[j-1] = A[mid +j];
    L[l1] = 1000000;
    R[l2]  = 10000000;
    int i=0,j=0;
    for(int k=low; k<=high; k++)
        if(L[i]< R[j])
        {
            A[k]= L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
}
int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>A[i];
    MergeSort(0,m-1);
    for(int i=0;i<m;i++)
        cout<<A[i]<<ends;
        cout<<endl;
    return 0;
}
