#include <bits/stdc++.h>
#define pii pair<long long, long long>

using namespace std;

struct point {
    double x, y, z;
    void scan() {
        cin >> x >> y >> z;
    }
};

double square(double a) {
    return a * a;
}

double dist(point a, point b) {
    return sqrt(square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z));
} 

point new_point(point a, point b, double rat) {
    point res;
    res.x = (a.x * rat + b.x * (3.0 - rat))/3.0;
    res.y = (a.y * rat + b.y * (3.0 - rat))/3.0;
    res.z = (a.z * rat + b.z * (3.0 - rat))/3.0;
    return res;
}


int main()
{
    freopen("input.txt", "r", stdin);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++) {
        point a, b, p;
        a.scan();
        b.scan();
        p.scan();
        
        int iter = 100;
        double a_dis = 0.0, b_dis = 0.0;
        while(iter --) {
            point neara = new_point(a, b, 2.0);
            point nearb = new_point(a, b, 1.0);
            
            a_dis = dist(neara, p);
            b_dis = dist(nearb, p);
            
            if(a_dis > b_dis) a = neara;
            else b = nearb;
            
        }
        
        printf("Case %d: %.8lf\n", t, (a_dis + b_dis)/2.0);
    }
    
}