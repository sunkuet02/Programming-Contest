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
    map<string,int>mp;
    for(int te=1;te<=t;te++)
    {
        int subject_num ;
        string s;
        int day;
        cin>>subject_num;
        for(int i=0;i<subject_num;i++)
        {
            cin>>s>>day;
            mp[s] = day;
        }
        int req;
        cin>>req>>s;
        if(mp.find(s)!=mp.end())
        {
            int a =mp.find(s)->second;
            if(req>=a)
                cout<<"Case "<<te<<": Yesss"<<endl;
            else if(a>req && a-req<=5)
                cout<<"Case "<<te<<": Late"<<endl;
            else
                cout<<"Case "<<te<<": Do your own homework!"<<endl;
        }
        else
            cout<<"Case "<<te<<": Do your own homework!"<<endl;
        mp.clear();
    }
    return 0;
}
