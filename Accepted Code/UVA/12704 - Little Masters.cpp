#include <bits/stdc++.h>

using namespace std;

int main()
{
    int te;

    cin>>te;
    for(int t =1;t<=te;t++)
    {
        int a,b,c;
        double x,y,r;
        cin>>a>>b>>c;
        r  = double(c);
        x = double (a);
        y = double(b);



        double dis = sqrt(x*x + y*y);
        double temp = 2.0 * r;
        x = r - dis ;
        y = temp - x;

        printf("%.2lf %.2lf\n",x,y );
    }

}

