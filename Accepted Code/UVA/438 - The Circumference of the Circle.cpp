#include<bits/stdc++.h>

using namespace std;

double a , b, c;

double lineEquationFromTwoPoint(double x1 , double y1 , double x2, double y2)    // Ax +By = C Form
{
    double temp1 = y1 - y2;
    double temp2 = x1 - x2;
    a = temp1;
    b = (-1)*temp2;
    c = x1*temp1 - y1*temp2;
}

double x, y ;
double findIntersectingPoint(double a1, double b1, double c1 , double a2, double b2, double c2)
{
    double determinant = a1*b2 - b1*a2;
    x = (c1*b2 - c2*b1)/ determinant;
    y = (a1*c2 - a2*c1)/ determinant;
}


double findPerpendicularLineEquationPassingPoint(double a1 , double b1, double c1  , double x1 , double y1)
{
    double temp = a1;
    a = (-1) * b1;
    b = a1;

    c = a * x1 + b * y1;
}

int main()
{

    double x1,x2,x3,y1,y2,y3;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1, &y1 , &x2 , &y2 , &x3 , & y3)!=EOF)
    {
        lineEquationFromTwoPoint(x1,y1,x2,y2);

        double A1 = a;
        double B1 = b;
        double C1 = c;
        //cout<<a<<ends<<b<<ends<<c<<endl;

        lineEquationFromTwoPoint(x2,y2,x3,y3);

        double A2 = a;
        double B2 = b;
        double C2 = c;
        //cout<<a<<ends<<b<<ends<<c<<endl;
        findPerpendicularLineEquationPassingPoint(A1, B1 , C1, (x1+x2)/2.0 , (y1+y2)/2.0);
         A1 = a;
         B1 = b;
         C1 = c;
        // cout<<a<<ends<<b<<ends<<c<<endl;
         findPerpendicularLineEquationPassingPoint(A2, B2 , C2, (x3+x2)/2.0 , (y3+y2)/2.0);
         A2 = a;
         B2 = b;
         C2 = c;
         //cout<<a<<ends<<b<<ends<<c<<endl;

         findIntersectingPoint(A1, B1, C1 , A2, B2, C2);

         double radius = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
         printf("%.2lf\n",2*3.141592653589793*radius);
    }

}

