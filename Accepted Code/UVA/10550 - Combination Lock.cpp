#include<bits/stdc++.h>

using namespace std;

int main() {
        int in, a,b,c;
        while(scanf("%d %d %d %d", &in, &a, &b, &c) &&(in || a || b || c)) {
                int sum = 3 * 360;

                if(in > a) sum += (in - a) * 9;
                else sum += (40 + in - a) * 9;

                if(b < a) sum += (40 + b - a) * 9;
                else sum += (b - a)* 9;

                if(b > c) sum += (b - c)*9;
                else sum += (40 + b - c)*9;
                cout << sum << endl;
        }
}

