#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    int lcs[50][50];
    int A[25],atemp[25];
    int B[25],btemp[25];
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }
    while(scanf("%d",&B[0])!=EOF)
    {

        for(int i=1;i<a;i++)
            scanf("%d",&B[i]);

        for(int i = 0;i<a;i++)
                btemp[i] = B[i];

        for(int i = 1;i<=a;i++)
                atemp[i-1] = A[i-1];

        for(int i = 1;i<=a;i++)
                B[A[i-1]-1] = i;
        for(int i = 1;i<=a;i++)
                atemp[btemp[i-1]-1] = i;

        for(int i=0;i<=a;i++)
            lcs[i][0]=0;
        for(int i=0;i<=a;i++)
            lcs[0][i]=0;
        for(int i=1;i<=a;i++)
            for(int j=1;j<=a;j++)
            {
                if(atemp[i-1]==B[j-1])
                    lcs[i][j]=1+lcs[i-1][j-1];
                else
                {
                    if(lcs[i-1][j]>=lcs[i][j-1])
                        lcs[i][j]=lcs[i-1][j];
                    else
                        lcs[i][j]=lcs[i][j-1];
                }
            }
//            if(lcs[a][a]>max)
                printf("%d\n",lcs[a][a]);
//            else
//                cout<<max<<endl;
    }
    return 0;
}
