#include<bits/stdc++.h>

using namespace std;



int main()
{
   int a,b,c,d,e,f;
   while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
   {
       double p = double(a);
       double q = double (b);
       double r = double (c);
       double s = double (d);
       double t = double (e);
       double u = double (f);

       double low = 0.0;
       double high = 1.0;
       double mid = (low+high)/2;
       bool flag = false;
       double temp;
       while((high-low)>0.000000000001)
       {
           mid = (low+high)/2;

           temp =  p * exp((-1)*mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t *mid *mid + u;

           if(temp <=1e-10  && temp >= -1e-10)
           {

               flag = true;
               break;

           }

           else if(temp <0.0)
           {
               high = mid;

           }
           else if(temp>0)
           {
               low = mid;
           }

           // cout<<high <<ends<<low<<ends<<mid<<ends<<temp<<endl;
       }

       if(flag )
       {
           printf("%.4lf\n",mid);
       }
       else
       {
           cout<<"No solution"<<endl;
       }

   }


}

