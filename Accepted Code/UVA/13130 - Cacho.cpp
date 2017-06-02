#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    
    for(int t = 1; t<= test; t++){
        int prv;
        scanf("%d", &prv);
        
        bool is = true;
        for(int i = 1; i<= 4; i++ ) {
            int cur;
            scanf("%d", &cur);
            if(cur != prv + 1) {
                is = false;
            }
            prv = cur;
        }
        if(is) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
}