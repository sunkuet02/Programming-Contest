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

int main()
{
    int N,No[15];
    cin>>N;
    for(int test=0;test<N;test++)
    {
        for(int i=0;i<=9;i++)
            No[i]=0;
        int num;
        cin>>num;
        for(int i=1;i<=num;i++)
        {
            int a=i;
            while(a)
            {
                int b=a%10;
                No[b]++;
                a=a/10;
            }
        }
        cout<<No[0];
        for(int i=1;i<=9;i++)
            cout<<" "<<No[i];
        cout<<endl;
    }
    return 0;
}
