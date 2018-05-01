#include <bits/stdc++.h>
#define pii pair<long long, long long>

using namespace std;

vector<pii> points;

struct coeff {
    long long a, b, c;
};

coeff cal_coeff(pii one, pii two) {
    coeff res;
    
    res.a = one.second - two.second;
    res.b = two.first - one.first;
    
    res.c = one.first * (one.second - two.second) - one.second * (one.first - two.first);
    return res;
} 

bool inlinee(coeff l1, pii p) {
    if(p.first * l1.a + p.second * l1.b == l1.c) return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    int test;
    cin >> test;
    
    for(int t = 1; t <= test; t++) {
        points.clear();
        int n;
        cin >> n;
        
        for(int i = 0; i < n ; i++) {
            pii a;
            cin >> a.first >> a.second;
            points.push_back(a);
        }
        
        if(n <= 2) {
            cout << "Case " << t << ": " << n << endl;
            continue;
        }
        int mx = 0;
        for(int i = 0; i < n; i++ ) {
            for(int j = i + 1; j < n; j++) {
                coeff ab = cal_coeff(points[i], points[j]);
                int cnt = 0;
                for(int k = j + 1; k < n; k++) {
                    if(inlinee(ab, points[k])) cnt ++;
                    //if(cnt > 0) cout << i << " " << j << " " << k << endl;
                }
                mx = max(mx, cnt);
            }
        }
        cout << "Case " << t << ": " << mx + 2 << endl;
    }
}
