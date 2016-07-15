#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int m;
    int Array[10010];
    while(scanf("%d",&m) && m)
    {
        for(int i =0; i<m; i++)
        {
            cin>>Array[i];
        }

        int max_so_far = 0;
        int max_ending_here = 0;

        for(int i =0; i<m; i++)
        {

            max_ending_here += Array[i];

            if(max_ending_here < 0 )
                max_ending_here = 0;
            if(max_so_far<max_ending_here)
                max_so_far = max_ending_here ;
        }
        if(max_so_far ==0 )
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",max_so_far);

    }

}

