#include<stdio.h>
main()
{
    char st1[100],st2[100];
    int a,b,c,i,d,e,j;
    scanf("%d",&a);
    getchar();
    for(b=1;b<=a;b++)
    {
        gets(st1);
        gets(st2);
        i=j=c=d=e=0;
        while(st1[i]!='\0' && st2[j]!='\0')
        {
            if(st1[i]==st2[j])
            {
                i++;
                j++;
                continue;
            }
            else if(st1[i]==' ')
            {
                c++;
                j++;
                continue;
            }
            else
            {
                i++;
                printf("Case %d: Wrong Answer\n",b);
                break;
            }
        }
        if(i==j)
            printf("Case %d: Yes\n",b);
        else if(c>0)
            printf("Case %d: Output Format Error\n",b);
    }
    return 0;
}
