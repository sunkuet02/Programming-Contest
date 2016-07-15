#include<stdio.h>
#include<string.h>
int coin[11] = {1,2,4,10,20,40,100,200,400,1000,2000};
long long int value[6010];
int main()
{
    int i,j;
    memset(value,0,sizeof(value));
    value[0] = 1;
    for(i=0;i<11;i++)
        for(j = coin[i];j<6001;j++)
            value[j] = value[j] + value[j-coin[i]];
    float m;
    while(1)
    {
        scanf("%f",&m);
        if(m == 0.00)
            break;
        int a = (int)(m*20);
        printf("%6.2f",m);
        printf("%17lld\n",value[a]);
    }
    return 0;
}
