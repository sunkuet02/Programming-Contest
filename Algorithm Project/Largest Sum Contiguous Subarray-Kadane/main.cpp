#include <iostream>
#include<vector >
using namespace std;

vector<int>Array;
int LargestSumSubArray()
{
    int max_so_far = 0;
    int max_ending_here = 0;

    for(int i =0;i<Array.size();i++)
    {
        max_ending_here +=Array[i];

        if(max_ending_here < 0 )
             max_ending_here = 0;
        if(max_so_far<max_ending_here)
            max_so_far = max_ending_here ;
    }
    return max_so_far;
}
int main()
{
    int m;
    cin>>m;
    for(int i =0;i<m;i++)
    {
        int a;
        cin>>a;
        Array.push_back(a);
    }
    int maximum = LargestSumSubArray();
    cout<<maximum<<endl;

}
