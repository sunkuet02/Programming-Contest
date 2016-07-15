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
    temp = a1;
    a = (-1) * b1;
    b = a1;

    c = (-1)*a * x1 + b * y1;
}

int main()
{


}
