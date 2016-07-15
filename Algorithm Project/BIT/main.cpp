   /* ******************************************************
   *  Md. Abdulla-Al-Sun
   *  Codeforces: sun.  , Topcoder : sun.
   *  Uva: sun. , SPOJ : sun_kuet  , LOJ : 5002 CodeChef: sun_kuet
   *  KUET, Bangladesh
   ****************************************************** */

#include <bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}
#define LL long long int
#define sz 100005
#define mod 1000000007
using namespace std;

int Tree[sz];
int n ;

int query(int idx)
{
    int sum = 0;
    while(idx)
    {
        sum += Tree[idx];
        idx -= (idx & -idx) ;
    }
    return sum;
}

void update(int idx, int val)
{
    while(idx <= n)
    {
        Tree[idx] += val;
        idx += (idx & -idx);
    }
}

int readNumber(int idx)
{
    int val = Tree[idx];

    if(idx > 0)
    {
        int z = idx - (idx & -idx) ;
        idx -- ;

        while(idx != z )
        {
            val -= Tree[idx] ;

            idx -= (idx & -idx) ;
        }
    }
    return val;
}

int main()
{
    //READ();
    int test;
    scan(test);
    rep1(t,test)
    {
        memset(Tree, 0 , sizeof(Tree));
        int q;
        scan(n);scan(q);
        Tree[0] = 0 ;
        rep1(i,n)
        {
            int a;
            scan(a);
            update(i,a);
        }
        printf("Case %d:\n",t);
        while(q--)
        {
            int type, i, j;
            scan(type);scan(i);
            if(type ==1 )
            {
                int val = readNumber(++i);
                printf("%d\n",val ) ;
                update(i,(-1)* (val) );
            }
            else if(type == 2)
            {
                scan(j);
                update(++i, j);
            }
            else
            {
                scan(j);
                int high = query(++j);
                int low = query(i);
                printf("%d\n",high - low);
            }
        }
    }

}
