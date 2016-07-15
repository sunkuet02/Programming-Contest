#include <bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int a)
{
    if(a && !(a & a-1))
        return true;
    else
        return false;
}

int main()
{
    int a ;
    cin>>a;
    bool val = isPowerOfTwo(a);
    if(val)
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
