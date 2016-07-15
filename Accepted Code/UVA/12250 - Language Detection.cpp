#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string st;
    for(int i=1;i<=2000;i++)
    {
        cin>>st;
        if(st=="#") break;
        else if(st=="HELLO")
            cout<<"Case "<<i<<": "<<"ENGLISH"<<endl;
        else if(st=="HOLA")
            cout<<"Case "<<i<<": "<<"SPANISH"<<endl;
        else if(st=="HALLO")
            cout<<"Case "<<i<<": "<<"GERMAN"<<endl;
        else if(st=="BONJOUR")
            cout<<"Case "<<i<<": "<<"FRENCH"<<endl;
        else if(st=="CIAO")
            cout<<"Case "<<i<<": "<<"ITALIAN"<<endl;
        else if(st=="ZDRAVSTVUJTE")
            cout<<"Case "<<i<<": "<<"RUSSIAN"<<endl;
        else
            cout<<"Case "<<i<<": "<<"UNKNOWN"<<endl;
    }
    return 0;
}
