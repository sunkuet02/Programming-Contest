#include<bits/stdc++.h>

using namespace std;
int lcs[100][100];

vector<char > v;
vector<vector<char> > s;
string A,B;
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
    if(m==0 || n==0)
    {
        s.push_back(v);
        return 0;
    }
    if(A[m-1]==B[n-1])
    {
        v.push_back(A[m-1]);
        find_sequence(m-1,n-1);
        v.pop_back();
    }
    else if(lcs[m-1][n]>lcs[m][n-1])
    {
        find_sequence(m-1,n);
    }
    else
    {
        find_sequence(m,n-1);
        find_sequence(m-1,n);
    }
}
int main()
{
    while(getline(cin,A))
    {
        getline(cin,B);
        int c=LCS();
        cout<<c<<endl;
        int m=A.size();
        int n=B.size();
        find_sequence(m,n);
        sort(s.begin(), s.end());
        for(int i = 0 ; i< s.size() ; i++ )
        {
            for(int j = 0 ; j< s[i].size() ; j ++ )
                cout << s[i][j];
            cout << endl;
        }

        cout<<endl;
        v.clear();
    }
}
