#include<iostream>
#include<vector>
#include<cstdio>
#include<cctype>
using namespace std;
int lcs[2000][2000];
vector<string>v;
vector<string>A,B;
int LCS()
{
    int m=A.size();
    int n=B.size();
    for(int i=0; i<=m; i++)
        lcs[i][0]=0;
    for(int i=0; i<=n; i++)
        lcs[0][i]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(A[i-1]==B[j-1])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                    lcs[i][j]=lcs[i-1][j];
                else
                    lcs[i][j]=lcs[i][j-1];
            }

    return lcs[m][n];
}
int find_sequence(int m,int n)
{
    if(m==0 || n==0) return 0;
    if(A[m-1]==B[n-1])
    {
        v.push_back(A[m-1]);
        find_sequence(m-1,n-1);
    }
    else if(lcs[m-1][n]>lcs[m][n-1])
    {
        find_sequence(m-1,n);
    }
    else
        find_sequence(m,n-1);
}
int main()
{
    string s1,s2,s3;
    int i,j=0;
    while(getline(cin,s1))
    {
        for(;;)
        {
            if(j!=0) getline(cin,s1);
            j++;
            if(s1=="#")
                break;
            for(i=0;i<s1.size();i++)
            {
                if(s3.size()==0 && s1[i]==' ')
                    continue;
                else if(!isspace(s1[i]))
                {
                    s3.push_back(s1[i]);
                }
                else
                {
                    A.push_back(s3);
                    s3.clear();
                }
            }
            if(s3.size()==0 && isspace(s1[i-1]));
            else A.push_back(s3);
            s3.clear();
        }
         for(;;)
        {
            getline(cin,s1);
            if(s1=="#")
                break;
            for(int i=0;i<s1.size();i++)
            {
                if(s3.size()==0 && s1[i]==' ')
                    continue;
                else if(!isspace(s1[i]))
                {
                    s3.push_back(s1[i]);
                }
                else
                {
                    B.push_back(s3);
                    s3.clear();
                }
            }
            if(s3.size()==0 && isspace(s1[i]));
            else B.push_back(s3);
            s3.clear();
        }
        int c=LCS();
        int m=A.size();
        int n=B.size();
        find_sequence(m,n);
        i=v.size()-1;
        cout<<v[i];
        for(i--;i>=0;i--)
          cout<<" "<<v[i];
        cout<<endl;
        v.clear();
        A.clear();
        B.clear();
        j=0;
    }
    v.clear();
    return 0;
}

