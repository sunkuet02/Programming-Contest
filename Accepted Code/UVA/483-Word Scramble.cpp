#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    char sun[10000];
    vector<char>tonni,shompa;
    while(scanf("%[^\n]", &sun) != EOF)
    {
        getchar();
        for(int i=0;sun[i]!='\0';i++)
        {
            if(sun[i]==' ')
            {
                reverse(tonni.begin(),tonni.end());
                for(int m=0;m<tonni.size();m++)  shompa.push_back(tonni[m]);
                tonni.clear();
                shompa.push_back(sun[i]);
            }
            else if(sun[i+1]=='\0')
            {
                tonni.push_back(sun[i]);
                reverse(tonni.begin(),tonni.end());
                for(int m=0;m<tonni.size();m++)  shompa.push_back(tonni[m]);
                tonni.clear();
            }

            else
            tonni.push_back(sun[i]);
        }
        for(int n=0;n<shompa.size();n++)
            cout<<shompa[n];
        cout<<endl;
        shompa.clear();
    }
    return 0;
}
