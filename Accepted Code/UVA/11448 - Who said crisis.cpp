#include<vector>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string st1,st2;
    int a,b,c,d,i,j,k;
    cin>>a;
    getchar();
    char sun[100]={0};
    char shompa[100]={0};
    vector<char>s1(100,0),s2(100,0);
    for(int i=1;i<=a;i++)
    {
        cin>>st1>>st2;
        for(int j=0;st1[j]!='\0';j++)
            s1.push_back(st1[j]);
        for(int j=0;st2[j]!='\0';j++)
            s2.push_back(st2[j]);
        int m=s1.size()-1;
        int n=s2.size()-1;
        if(n>m) s1.swap(s2);
        if(n==m)
        {
            if(st1[m]<st2[n])
            {
                a=st1[m]-48;
                b=st2[n]-48;
                a+=10;
            }
        }
    }
}
