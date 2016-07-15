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
    long fib[100];
    long  f1=0,f2=1,f3;
    for(int i=0;i<=51;i++)
    {
        f3 = f1+f2;
        fib[i] = f3;
        f1 = f2;
        f2 = f3;
    }
    int te;
    cin>>te;
    for(int t = 1;t<=te;t++)
    {
        int a;
        cin>>a;
        cout<<"Scenario #"<<t<<":"<<endl<<fib[a]<<endl;
            cout<<endl;
    }
    return 0;
}
