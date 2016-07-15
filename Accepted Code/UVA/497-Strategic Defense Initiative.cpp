/***************8WA,1RE then accepted***********/

#include <iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int lis_seqence[300000];
int L[300000];
int parent[30000];

vector<int>path;
int LIS(int n)
{
    for(int i=0; i<=n; i++)
    {
        L[i]=1;
        parent[i] = i;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(lis_seqence[i]<lis_seqence[j])
            {
                if(L[j]<L[i]+1)
                {
                    L[j]=L[i]+1;
                    parent[j] = i;
                }
            }
        }
    }
    int maxLength=0;
    for(int i=0; i<n; i++)
        if(maxLength<L[i])
            maxLength=L[i];
    cout<<"Max hits: "<<maxLength<<endl;
    return maxLength;
}

int find_path(int x)
{
    if(parent[x]==x)
    {
        path.push_back(lis_seqence[x]);
        return 0;
    }
    else
    {
        path.push_back(lis_seqence[x]);
        find_path(parent[x]);
    }
}

int main()
{
    int b;
    //freopen("input.txt","r",stdin);
    cin>>b;
    getchar();
    getchar();
    string s;
    for(int j=1; j<=b; j++)
    {
        int k =0;
        while(1)
        {
            int a = 0;
            getline(cin,s);
            if(s=="")
                break;
            for(int i=0; i<s.size(); i++)
                a = a*10 +(s[i]-48);
            lis_seqence[k++] = a;
        }
        if(k==0)
        {
            cout<<"Max hits: "<<0<<endl;
            if(j!=b)
                cout<<endl;
            continue;
        }
        int maximum=LIS(k);
        int i;
        for(i=k-1; i>=0; i--)
            if(maximum==L[i])
                break;
        path.clear();
        find_path(i);
        for(int t=path.size()-1;t>=0;t--)
            cout<<path[t]<<endl;
        if(j!=b)
            cout<<endl;
    }
    return 0;
}

