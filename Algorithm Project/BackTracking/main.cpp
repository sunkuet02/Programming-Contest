#include <bits/stdc++.h>

using namespace std;

char arr[]= {'a','b','c','d'};
vector<char>result;
int taken[20]= {0};
void call(int n)
{
    if(result.size()==n)
    {
        for(int i=0; i<n; i++)
            printf("%c",result[i]);
        puts("");
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1;
            result.push_back(arr[i]);
            call(n);
            taken[i]=0;
            result.pop_back();
        }
    }
}
int main()
{
    int n = 3;
    call(n);
}
