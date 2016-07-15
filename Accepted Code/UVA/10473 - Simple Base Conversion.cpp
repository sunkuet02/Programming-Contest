#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    long int num,hex,dec,i,j,a,m;
    string st;
    char ch;
    vector<char>h;
    for(;;)
    {
        cin>>st;
        if(st[0]=='-') break;
        else if(st[0]=='0' && st[1]=='x')
        {
            j=0;
            dec=0;

            for(i=st.size()-1;i>=2;i--)
            {
                if(st[i]=='A') m=10;
                else if(st[i]=='B') m=11;
                else if(st[i]=='C') m=12;
                else if(st[i]=='D') m=13;
                else if(st[i]=='E') m=14;
                else if(st[i]=='F') m=15;
                    else
                    {
                        m=st[i]-48;
                    }
                dec+=m*(pow(16,j));
                j++;
            }
            cout<<dec<<endl;
        }
        else
        {
            dec=0;

            for(i=0;i<st.size();i++)
            {
                dec=dec*10+st[i]-48;
            }

            for(;;)
            {
                if(dec<16)
                {
                    a=dec;
                    if(a==10) h.push_back('A');
                    else if(a==11) h.push_back('B');
                    else if(a==12) h.push_back('C');
                    else if(a==13) h.push_back('D');
                    else if(a==14) h.push_back('E');
                    else if(a==15) h.push_back('F');
                    else
                    {
                        ch=a+48;
                        h.push_back(ch);
                    }
                    break;
                }
                a=dec%16;
                if(a==10) h.push_back('A');
                else if(a==11) h.push_back('B');
                else if(a==12) h.push_back('C');
                else if(a==13) h.push_back('D');
                else if(a==14) h.push_back('E');
                else if(a==15) h.push_back('F');
                else
                {
                    ch=a+48;
                    h.push_back(ch);
                }
                dec=dec/16;

            }
            h.push_back('x');
            h.push_back('0');
            for(i=h.size()-1;i>=0;i--)
                cout<<h[i];
                cout<<endl;
            h.clear();
        }
    }
    return 0;
}
