#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
int main()
{
    int a[32],b[32],in1,in2,sum,total;

    while(scanf("%d %d",&in1,&in2)!=EOF)
    {
//        memset(a,0,sizeof(a));
//        memset(b,0,sizeof(b));
        int p = in1;
        int q  = in2;
        int s=0,t=0;
        while(p>0)
        {
            s++;
            p/=2;
        }
        while(q>0)
        {
            t++;
            q/=2;
        }
        p = in1;
        q = in2;
        int j;
        if(s>t)
            j = s;
        else
            j = t;
        int i = 0;
        for(i = 0;i<j;i++)
        {
            a[i] = p%2;
            b[i] = q%2;
            p/=2;
            q/=2;
        }
        total = 0;
        for(i = 0;i<j;i++)
        {
            if(a[i] + b[i] == 1)
                total+= pow(2,i);
        }
        printf("%d\n",total);
    }
}
