#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int te;
    //freopen("input.txt","r",stdin);
    scanf("%d",&te);
    int t,ar_th,cu_th,cu_tm,num,ar_tm,traveltime,j,min,total_cu,total_ar,tt;
    for(t= 1;t<=te;t++)
    {
        scanf("%d %d:%d",&num,&cu_th,&cu_tm);
         j;
         total_cu = cu_tm +(cu_th*60);
         total_ar;
         min = 50000;
        for(j = 0;j<num;j++)
        {
            scanf("%d:%d %d",&ar_th,&ar_tm,&traveltime);
            total_ar = ar_tm+(ar_th*60)+traveltime;
            if((ar_tm+(ar_th*60))<total_cu)
                total_ar +=1440;
             tt = total_ar - total_cu;
            if(tt<min)
                min = tt;
        }
        printf("Case %d: %d\n",t,min);
    }

    return 0;
}
