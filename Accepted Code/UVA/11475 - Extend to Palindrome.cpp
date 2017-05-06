#include <bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define Read freopen("input.txt","r",stdin);
#define Write freopen("output.txt","w",stdout);
#define mem(a,val) memset(a,val, sizeof(a) );
#define LL long long int
#define mxx 65536
#define sz 200005
#define MAX 1300000

class j;
using namespace std;


/***************************Implementation*********************/

int kmpTemplateArray[100005];

void fillPatternTemplate(string str) {
    int j = 0;
    for(int i = 1 ; i < (int)str.size() ; i++ ) {
        if(str[i] == str[j]) {
            kmpTemplateArray[i] = j + 1;
            j++;
        }
        else {
            while(str[i] != str[j] && j) {
                j = kmpTemplateArray[j-1];
            }
            if(str[i] == str[j]) {
                kmpTemplateArray[i] = j + 1;
            } else {
                j = 0;
            }
        }
    }
}

int kmpSearch(string text, string pattern) {
    int j = 0 ;
    for(int i = 0 ; i< (int)text.size(); i++ ) {
        if(text[i] == pattern[j]) {
            j++ ;
        } 
        else {
            while(text[i] != pattern[j] && j) {
                j = kmpTemplateArray[j-1];
            }
            if(text[i] == pattern[j]) {
                j++;
            }
        }
        //cout <<text[i] << " " << pattern[j] << " " << i << " " << j << endl;
    }
    return j;
}

void print(int arr[], int size) {
    rep(i,0, size) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    string pattern, input;
    while(cin >> input) {
        mem(kmpTemplateArray, 0);
        pattern = input;
        reverse(pattern.begin(), pattern.end());
        fillPatternTemplate(pattern);
        int nextOfPattern = kmpSearch(input, pattern);
        
        for(int i = nextOfPattern ; i < (int)pattern.size(); i++ ) {
            input.push_back(pattern[i]);
        }
        cout << input << endl;
    }
}
