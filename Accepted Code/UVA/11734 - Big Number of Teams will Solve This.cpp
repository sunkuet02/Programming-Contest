#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string judge,team;
    int i,m,space;
    cin>>m;
    getchar();
    for(i=1;i<=m;i++)
    {
        getline(cin,team);
        getline(cin,judge);
        int j,k;
        j=k=0;
        space=0;
        while(team[j]!='\0' && judge[k]!='\0')
        {
            if(team[j]==judge[k])
            {
                j++;
                k++;
            }
            else if(team[j]==' ')
            {
                j++;
                space++;
            }
            else
            {
                space=-100;
                break;
            }
        }
        if(space>=0 && judge[k]=='\0')
        while(team[j]!='\0')
        {
            if(team[j]==' ')
            {
                space++;
            }
            j++;
        }
        if(space==0 && team.size()==judge.size())
            cout<<"Case "<<i<<": Yes"<<endl;
        else if(space>0 &&(team.size()-space)==judge.size())
            cout<<"Case "<<i<<": Output Format Error"<<endl;
        else
           cout<<"Case "<<i<<": Wrong Answer"<<endl;

    }
    return 0;
}
