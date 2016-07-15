   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL long long int
#define mx 15
#define MAX 15
#define sz 10005
using namespace std;

int lcs[105][105];
string L[105][105] ;

char A[105],B[105];
int m , n;

int LCS()
{
    for(int i=0; i<=m; i++)
    {
        lcs[i][0]=0;
        L[i][0] = "";
    }
    for(int i=0; i<=n; i++)
    {
        lcs[0][i]=0;
        L[0][i] = "";
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(A[i-1]==B[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
                L[i][j] = L[i-1][j-1] + A[i-1];
            }
            else if(lcs[i-1][j]>lcs[i][j-1])
            {
                lcs[i][j]=lcs[i-1][j];
                L[i][j] = L[i-1][j];
            }
            else if(lcs[i-1][j]<lcs[i][j-1])
            {
                lcs[i][j]=lcs[i][j-1];
                L[i][j] = L[i][j-1];
            }
            else
            {
                lcs[i][j]=lcs[i][j-1];
                L[i][j] = min(L[i-1][j], L[i][j-1]);
            }

    return lcs[m][n];
}

int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        scanf("%s %s",A,B);

        int i;
        for(i = 0 ; A[i]!='\0' ; i++ );  m = i;
        for(i = 0 ; B[i]!='\0' ; i++ );  n = i;

        int c=LCS();

        printf("Case %d: ",t);
        if(!c)
        {
            printf(":(\n");
        }
        else
        {
            cout << L[m][n] ;
            printf("\n");
        }
    }
}

