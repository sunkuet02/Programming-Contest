#include<iostream>
#include<cstdio>
using namespace std;

int main()
{

    long int ar[105][105];
    int test;
    cin>>test;
    for(int t =0;t<test;t++)
    {

        int no;
        scanf(" N = %d",&no);
        bool flag = true;

        for(int i =0;i<no;i++)
        {
            for(int j =0;j<no;j++)
            {

                cin>>ar[i][j];
                if(ar[i][j]<0)
                    flag =false;

            }
        }

        if(!flag)
        {
            printf("Test #%d: Non-symmetric.\n",t+1);
            continue;
        }

        flag = true;

       int temp = (no/2) +1;
       for(int i =0;i<no;i++)
        {
            for(int j =0;j<no;j++)
            {

                if(ar[i][j] !=  ar[no-i-1][no-j-1])
                {
                    flag =false;
                    break;
                }
            }
            if(!flag)
                break;
        }

        if(flag)
        {
            printf("Test #%d: Symmetric.\n",t+1);
        }
        else
        {
            printf("Test #%d: Non-symmetric.\n",t+1);
        }

    }
}

