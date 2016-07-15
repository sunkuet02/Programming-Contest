#include<stdio.h>
int main()
{
    int a,b,c,d,m,n,j,k,l,i;
    for(;;)
    {
        scanf("%d",&c);
        if(c==0)
            break;
        scanf("%d %d",&a,&b);
        for(i=1;i<=c;i++)
        {
            scanf("%d %d",&m,&n);
            if(a==m || b==n)
                printf("divisa\n");
            else if(m>a && n>b)
                printf("NE\n");
            else if(m<a && n>b)
                printf("NO\n");
            else if(m<a && n<b)
                printf("SO\n");
            else if(m>a && n<b)
                printf("SE\n");
        }
    }
    return 0;
}
