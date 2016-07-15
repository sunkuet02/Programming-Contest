#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a, &b , &c)!=EOF)
    {
        double s = (a+b+c)/2;
        if(s==0)
        {
            printf("The radius of the round table is: 0.000\n");
            continue;


            }
        double r = sqrt(((s-a)*(s-b)*(s-c))/s);
        printf("The radius of the round table is: %.3lf\n",r);
    }
}


