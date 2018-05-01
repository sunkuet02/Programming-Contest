#include <bits/stdc++.h>

using namespace std;

int get_order(int a, int b) {
    if(a - b < 0) return -1;
    return 1;
}

bool is_ordered(int a[]) {
    int order = get_order(a[1], a[0]); 
    
    for(int i = 2; i < 10; i ++) {
        if(get_order(a[i], a[i-1]) != order) {
            return false;
        }
    }
    
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    int tests, a[10];
    
    cin >> tests;
    
    cout << "Lumberjacks:" << endl;
    while(tests --) {
        for(int i = 0; i < 10 ; i++) {
            cin >> a[i];
        }
        
        if(is_ordered(a)) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
        
    }
}