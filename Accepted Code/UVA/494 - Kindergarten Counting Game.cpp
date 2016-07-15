#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    vector<char>sun;
    int i;
    char shompa[5000];
    while(scanf("%[^\n]",&shompa)!=EOF)
    {
        getchar();
        int count=0;
        for(i=0;shompa[i]!='\0';i++)
        {
            if(isupper(shompa[i]) || islower(shompa[i]))
            {
                    sun.push_back(shompa[i]);
            }

            else if(!sun.empty())
            {
                count++;
                sun.clear();
            }
        }
        if(sun.size()!=0 && shompa[i]=='\0')
            {
                count++;
                sun.clear();
            }
        cout<<count<<endl;
    }
}
