#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int maximum(int a,int b)
{
    if(a>=b) return a;
    return b;
}
int LCS(A[],B[])
{
    for(int i=0;i<=m;i++)
        {
            lcs[i][0]=0;
        }
        for(int j=0;j<=n;j++)
            lcs[0][j]=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                    lcs[i][j]=1+lcs[i-1][j-1];
                else
                    lcs[i][j]=maximum(lcs[i-1][j],lcs[i][j-1]);

            }
        }
        return  result=lcs[m][n];
}
int main()
{



    return 0;
}
