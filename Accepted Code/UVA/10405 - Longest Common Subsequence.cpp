#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int lcs[2000][2000];
int LCS(string A,string B)
{
    int m=A.size();
    int n=B.size();
    for(int i=0; i<=m; i++)
        lcs[i][0]=0;
    for(int i=0; i<=n; i++)
        lcs[0][i]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(A[i-1]==B[j-1]){
                lcs[i][j]=1+lcs[i-1][j-1];}
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                    lcs[i][j]=lcs[i-1][j];
                else
                    lcs[i][j]=lcs[i][j-1];

            }
    return lcs[m][n];
}
int main()
{
    string s1,s2;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        int a=LCS(s1,s2);
        cout<<a<<endl;
    }

}
