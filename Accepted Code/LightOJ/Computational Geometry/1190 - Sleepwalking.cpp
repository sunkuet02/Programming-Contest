#include<bits/stdc++.h>
#define INF 21000
#define ll long long
using namespace std;

struct point {
    ll x, y;
    void print() {
        cout << x << " " << y << endl;
    }
    void get() {
        scanf("%lld %lld",&x, &y);
    }
};

bool onsegment(point p, point q, point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

ll orientation(point p, point q, point r) {
    ll orientationMarker = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(orientationMarker == 0) return 0;
    
    return orientationMarker > 0 ? 1 : 2;
}

int intersectKoreKiNa(point p1, point q1, point p2, point q2) {
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    
    if(o1 != o2 && o3 != o4) return true;
    
    if(o1 ==0 && onsegment(p1, p2, q1)) return 2; 
    if(o2 ==0 && onsegment(p1, q2, q1)) return 2;
    if(o3 ==0 && onsegment(p2, p1, q2)) return 2;
    if(o4 ==0 && onsegment(p2, q1, q2)) return 2;
    
    return false;
}

bool isInsidePolygon(vector<point> polygon, point p) {
    int count = 0 ;
    
    point infinitePoint;
    infinitePoint.x = INF;
    infinitePoint.y = INF;
    
    for(int i = 0 ; i < polygon.size();  i++ ) {
        int next = (i+1) % polygon.size();
        
        if(intersectKoreKiNa(polygon[i], polygon[next], p, infinitePoint)) {
            if(orientation(polygon[i], p, polygon[next]) == 0) {
                return onsegment(polygon[i], p, polygon[next]);
            }
            
            int o1 = orientation(p, infinitePoint, polygon[i]);
            int o2 = orientation(p, infinitePoint, polygon[next]);
            
            if( (o1 && o2) || (!o1 && o2 == 1) || (o1 == 1 && !o2) ) count ++ ;
            //Or
            //if( (o1 && o2) || (!o1 && o2 == 2) || (o1 == 2 && !o2) ) count ++ ;
        }
    }
    return count % 2 == 1;
}

bool isInsidePolygon2(vector<point> polygon, point p) {
    int count = 0 ;
    
    point infinitePoint;
    infinitePoint.x = p.x + INF;
    infinitePoint.y = p.y + INF + 1;
    
    for(int i = 0 ; i < polygon.size();  i++ ) {
        int next = (i+1) % polygon.size();
        
        if(ll ret = intersectKoreKiNa(polygon[i], polygon[next], p, infinitePoint)) {
            if(ret == 2) return true;
            
            if( orientation(polygon[i], p, polygon[next]) == 0) {
                return onsegment(polygon[i], p, polygon[next]);
            }
            count ++ ;
            //if(count == 1) cout << i << " " << next << endl;
        }
    }
    return count % 2 == 1;
}

vector<point> v;
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d",&test);
    
    for(int t = 1; t <= test; t++ ) {
        v.clear();
        int n; 
        scanf("%d",&n);
        
        for(int i = 0 ; i < n ; i++ ) {
            point p;
            p.get();
            v.push_back(p);
        }
        
        int q;
        printf("Case %d:\n", t);
        scanf("%d",&q);
        
        while(q) {
            point p; p.get();
            isInsidePolygon(v,p) ? printf("Yes\n") : printf("No\n");
            q--;
        }
    }
}