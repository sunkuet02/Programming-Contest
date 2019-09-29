#include<bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while(test --) {
        int n;
        cin >> n;
        int mini = 100, maxi = -1;
        while(n--) {
            int a;
            cin >> a;
            if(mini > a) mini = a;
            if(maxi < a) maxi = a;
        }
        int mn = 100000;
        for(int i = 0; i < 100; i++) {
            mn = min(mn, abs(i - mini) + abs(mini - maxi) + abs(maxi-i));
        }
        cout << mn << endl;
    }
}

