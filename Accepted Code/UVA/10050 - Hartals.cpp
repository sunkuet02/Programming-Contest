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
    int t;
    cin>>t;
    int istaken[4000];
    for(int te=0;te<t;te++)
    {

        cin>>days;
        for(int i=0;i<=days;i++)
            istaken[i] = 0;
        int party;
        cin>>party;
        int total  = 0;
        for(int p = 1;p<=party;p++)
        {
            int hartal;
            cin>>hartal;
            for(int i =hartal;i<=days;i+=hartal)
            {
                if(!istaken[i])
                {
                    int a = i%7;
                    if(a!=6 && a!=0)
                    {
                        total++;
                    }
                    istaken[i]=1;
                }
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
