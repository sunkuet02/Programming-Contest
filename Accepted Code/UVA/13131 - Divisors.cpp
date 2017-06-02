#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    
    for(int t = 1; t<= test; t++){
        int n,k;
        scanf("%d %d", &n, &k);
        
        int sum = 0;
        
        for(int i = 1; i*i <= n; i++) {
            if((n/i)*i == n) {
                int bigger = n/i;
                
                if(i != bigger) {
                    if((i/k)*k != i) sum += i;
                    if((bigger/k)*k != bigger) sum += bigger;
                } else {
                    if((i/k)*k != i) sum += i;
                }
            }
        }
        printf("%d\n",sum);
    }
}