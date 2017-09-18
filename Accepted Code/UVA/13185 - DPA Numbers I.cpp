#include<bits/stdc++.h>
#define sz 100005
#define ll long long int
#define mod 1000000000 + 7

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    
    for(int t = 1; t <= test; t++) {
        int n;
        scanf("%d",&n);
        
        int sumOfDivisor = 0;
        
        for(int i = 2; i*i <= n ; i++) {
            if((n/i)*i == n) sumOfDivisor += i;
            if(i*i != n) {
                if((n/i)*i == n) sumOfDivisor += (n/i);
            }
        }
        
        sumOfDivisor ++ ;
        
        if(sumOfDivisor < n) printf("deficient\n");
        else if(sumOfDivisor == n) printf("perfect\n");
        else printf("abundant\n");
    }
}