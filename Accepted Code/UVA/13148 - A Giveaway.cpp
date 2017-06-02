#include<bits/stdc++.h>

using namespace std;

int numbers[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,47045881, 64000000, 85766121};


int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d",&n) && n) {
        bool special = false;
        for(int i = 0; i<21; i++ ) {
            if(numbers[i] == n) {
                special = true;
                break;
            }
        }
        
        if(special) {
            printf("Special\n");
        } else {
            printf("Ordinary\n");
        }
    }
}