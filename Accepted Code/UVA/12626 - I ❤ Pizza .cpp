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
    string s;
    int N;
    cin>>N;
    int A[8];
    getchar();
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<6;i++)
            A[i] = 0;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='M')
                (A[0])++;
            else if(s[i]=='A')
                (A[1])++;
            else if(s[i]=='R')
                (A[2])++;
            else if(s[i]=='G')
                (A[3])++;
            else if(s[i]=='I')
                (A[4])++;
            else if(s[i]=='T')
                (A[5])++;
        }
        A[1]= A[1]/3;
        A[2] = A[2]/2;
        int minn = A[0];
        for(int i=1;i<6;i++)
            if(minn>A[i])
                minn = A[i];
        cout<<minn<<endl;


    }
    return 0;
}
