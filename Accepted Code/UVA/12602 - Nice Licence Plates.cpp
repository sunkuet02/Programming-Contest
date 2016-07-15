#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

int main()
{
    string num_plate;
    int N;
    cin>>N;
    for(int test =1; test<=N; test++)
    {
        cin>>num_plate;
        int i=0;
        int sum_letter=0;
            sum_letter += ((num_plate[i]-65)*(26*26));
            i++;
            sum_letter += ((num_plate[i]-65)*(26));
            i++;
            sum_letter += (num_plate[i]-65);
            i+=2;
        int num_letter=0;
        for(;num_plate[i]!='\0';i++)
        {
            num_letter = num_letter*10 + (num_plate[i]-48);
        }
        int result = num_letter - sum_letter;
        if(result<=100 && result>=-100)
            cout<<"nice"<<endl;
        else
            cout<<"not nice"<<endl;
    }
    return 0;
}
