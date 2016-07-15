#include<stdio.h>
#include<string.h>

int coin[11] = {1,5,10,25,50};
long long int value[30005];
int main()
{
    int i,j;
    memset(value,0,sizeof(value));
    value[0] = 1;
    for(i=0;i<5;i++)
        for(j = coin[i];j<30001;j++)
            value[j] = value[j] + value[j-coin[i]];
    int m;

    while(scanf("%d",&m)!=EOF)
    {
        if(value[m]!=1)
            printf("There are %lld ways to produce %d cents change.\n",value[m],m);
        else
            printf("There is only 1 way to produce %d cents change.\n",m);
    }
    return 0;
}
