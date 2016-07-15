#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int temp1;
int LargestSumSubArray(int A [] , int m,int t)
{
    int max_so_far = -1;
    int max_ending_here = 0;
    temp1 = 0;
    int temp2 = 0,finala = 0,finalb,maxRange = 0;
    for(int i =1;i<m;i++)
    {
        max_ending_here += A[i];

        if(max_ending_here < 0 )
        {
             max_ending_here = 0;
            temp1 = i;
        }

        if(max_so_far<=max_ending_here && A[i]>=0)
        {

            temp2 = i;
            if(max_so_far<max_ending_here)
            {
                finala = temp1;
                finalb = temp2;
                maxRange = temp2 - temp1;
            }
            else if( max_so_far==max_ending_here && maxRange<(temp2 - temp1))
            {
                finala = temp1;
                finalb = temp2;
                maxRange = temp2 - temp1;
            }
            max_so_far = max_ending_here ;
        }
    }

    if(max_so_far>=0)
        printf("The nicest part of route %d is between stops %d and %d\n",t,finala+1,finalb+1);
    else
        printf("Route %d has no nice parts\n",t);

}
int main()
{
    int m;
    //freopen("input.txt","r",stdin);
    int Array[20010];
    int test;
    cin>>test;
    for(int t =1;t<=test;t++)
    {
        cin>>m;
        for(int i =1;i<m;i++)
        {
            cin>>Array[i];
        }
        int maximum = LargestSumSubArray(Array, m,t);


    }

}

