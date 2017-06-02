#include<bits/stdc++.h>

using namespace std;

int weights[100005];
int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    
    for(int t = 1; t<= test; t++){
        int M, W;
        scanf("%d %d", &M, &W);
        
        for(int i = 0; i < M; i++ ) {
            scanf("%d",&weights[i]);
        }
        sort(weights, weights + M);
        
        int total = 0;
        int cnt = 0;
        
        for(int i = 0 ; i< M ; i++ ) {
            total += weights[i];
            if(total < W) cnt ++;
        }
        
        printf("%d\n", cnt);
        
    }
}