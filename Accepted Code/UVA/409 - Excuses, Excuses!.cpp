#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<cctype>
using namespace std;
int main()
{
    int test_key,test_line,a,i,j;
    string st,line;
    char arrey[100];
    vector<string>store_key,key_test,result;
    int p=0;
    while(scanf("%d %d",&test_key,&test_line)!=EOF)
    {
        getchar();
        for(i=1;i<=test_key;i++)
        {
            cin>>st;
            store_key.push_back(st);
        }
        getchar();
        int max=-1;
        for(j=1;j<=test_line;j++)
        {
            a=0;
            int num=0;
            getline(cin,line);
            string sun;
            sun=line;
            for(i=0;i<line.size();i++)
            {
                if((line[i]>=65 && line[i]<=90)||(line[i]>=97 && line[i]<=122) )
                {
                    if(line[i]>=65 && line[i]<=90) line[i]=line[i]+32;
                    arrey[a++]=line[i];
                }

                else
                {
                    arrey[a++]='\0';
                    key_test.push_back(arrey);
                    a=0;
                    for(int q=0;q<store_key.size();q++)
                        if(store_key[q]==key_test[0]) num++;
                        key_test.clear();

                }
                if(i+1==line.size())
                {
                    arrey[a++]='\0';
                    key_test.push_back(arrey);
                    a=0;
                    for(int q=0;q<store_key.size();q++)
                        if(store_key[q]==key_test[0]) num++;
                        key_test.clear();
                }
            }
            if(num>max)
            {
                max=num;
                result.clear();
                result.push_back(sun);
            }
            else if(num==max)
            {
                result.push_back(sun);
            }
        }

        p++;
        cout<<"Excuse Set #"<<p<<endl;
        for(int b=0;b<result.size();b++)
        {
            cout<<result[b]<<endl;
        }
        if(p) cout<<endl;
        result.clear();
        store_key.clear();
    }
    return 0;
}
