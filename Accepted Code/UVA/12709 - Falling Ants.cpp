#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l,w,h;
    int n;

    while(cin>>n,n)
    {
        int maxh = 0,maxvol = 0;
        for(int i = 0;i<n;i++)
        {
            cin>>l>>w>>h;
            if(h>maxh)
            {
                maxvol = l*w*h;
                maxh = h;
            }
            else if(h== maxh)
            {
                if(maxvol<(l*w*h))
                    maxvol = l*w*h;
            }

        }
        cout<<maxvol<<endl;
    }
}

