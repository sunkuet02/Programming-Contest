#include<stdio.h>
int main()
{
    long int i,k,l,j,n,a[20];
    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        for(j=0;j<4;j++)
            scanf("%ld",&a[j]);
        for(k=1;k<4;k++)
            for(l=3;l>=k;l--)
                if(a[l-1]>a[l])
                {
                    n=a[l-1];
                    a[l-1]=a[l];
                    a[l]=n;
                }
        if((a[0]==a[1] && a[1]==a[2]) && a[2]==a[3])
            printf("square\n");
        else if(a[0]==a[1] && a[2]==a[3])
            printf("rectangle\n");
        else if((a[0]+a[1]+a[2])<=a[3])
        	printf("banana\n");
       	else
       		printf("quadrangle\n");
    }
    return 0;
}
