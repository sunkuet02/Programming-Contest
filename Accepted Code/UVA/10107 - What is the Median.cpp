#include<bits/stdc++.h>


using namespace std;

int main()
{
    vector<int>v;
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        v.push_back(n);
        sort(v.begin() , v.end());
        if(v.size()%2==1)
            cout<<v[v.size()/2]<<endl;
        else
            cout<<(v[(v.size()/2)] + v[(v.size()/2)-1] )/2<<endl;
    }
}

