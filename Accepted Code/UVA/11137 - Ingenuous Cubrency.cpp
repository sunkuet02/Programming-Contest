#include<stdio.h>
#include<string.h>


long long int value[10005];
int main()
{
    int coin[22];
    int i;
    for(i=0;i<=20;i++)
        coin[i] = (i+1)*(i+1)*(i+1);

    int j;
    memset(value,0,sizeof(value));
    value[0] = 1;
    for(i=0;i<21;i++)
        for(j = coin[i];j<10000;j++)
            value[j] = value[j] + value[j-coin[i]];
    int m;

    while(scanf("%d",&m)!=EOF)
    {
        printf("%lld\n",value[m]);
    }
    return 0;
}
