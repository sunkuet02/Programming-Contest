#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int test = 0;
    while(scanf("%d",&n) && n) {
        int reason = 0, given = 0 ;
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if(a) reason ++;
            else given ++;
        }
        cout << "Case " << ++test << ": " << reason - given << endl;
    }
}

