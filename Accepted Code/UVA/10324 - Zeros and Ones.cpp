#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    string s;
    int c = 1;
    freopen("input.txt","r",stdin);
    while(cin>>s)
    {
        int test;
        scanf("%d",&test);
        printf("Case %d:\n",c++);
        for(int t = 1;t<=test ;t++)
        {
            bool mark = true;
            int a,b;
            scanf("%d %d",&a,&b);
            int mx,mn;
            if(a>=b)
            {
                mx =a;
                mn = b;
            }
            else
            {
                mx = b;
                mn  = a;
            }


            char ch = s[mn];
            for(int j = mn+1;j<=mx;j++)
            {
                if(ch !=s[j])
                {
                    mark = false;
                    break;
                }

            }
            if(mark)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }


    }
    return 0 ;
}
