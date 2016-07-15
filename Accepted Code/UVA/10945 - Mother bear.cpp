#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{

    int count;
    string sun;
    vector<char>tonni;
    while(1)
    {
        getline(cin,sun);
        if(sun=="DONE") break;
        for(int i=0;i<sun.size();i++)
        {
            if(sun[i]>=65 && sun[i]<=90)
            {
                sun[i]=sun[i]+32;
                tonni.push_back(sun[i]);
            }
            else if(sun[i]>=97 && sun[i]<=122)
                tonni.push_back(sun[i]);
        }
        count=0;
        int m=(tonni.size()/2);
        int n=tonni.size()-1;
        for(int j=0;j<m;j++)
        {
            if(tonni[j]==tonni[n-j]) count=0;
            else
            {
                count=-1;

                break;
            }
        }
        if(count==0) cout<<"You won't be eaten!"<<endl;
        else if(count==-1) cout<<"Uh oh.."<<endl;
        tonni.clear();
    }
    return 0;
}
