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
#define sz 502
#define mod 1000000007
using namespace std;

int n,q,grid[sz][sz] ;
int tree[3*sz][3*sz] ;
int val[sz];
int R1, R2, C1, C2;

int init2DTree(int I , int node , int b, int e)
{
    if(b==e)
    {
        return tree[I][node] = val[b];
    }
    int mid = (b+e)/2;
    int left = 2*node;

    int r1 = init2DTree(I , left , b , mid );
    int r2 = init2DTree (I, left+1, mid+1, e);

    return tree[I][node] = max(r1, r2) ;
}

void initTree(int node , int b , int e)
{
    rep1(i,n)
    {
        val[i] = grid[i][b];
        rep(j,b,e)
        {
            val[i] = max(val[i],grid[i][j]);
        }
    }

    init2DTree(node, 1, 1 ,n);

    if(b==e)
        return;

    int mid = (b+e)/ 2;
    int left = 2*node;

    initTree(left , b, mid);
    initTree(left+1, mid + 1, e);
}

int Find2ndPart(int I , int node , int b, int e )
{
    if(b> R2 || e< R1 ) return 0;

    if(b>=R1 && e<=R2)
    {
        return tree[I][node];
    }

    int mid = (b+e) /2;
    int left = 2* node;

    return max ( Find2ndPart(I, left, b, mid) , Find2ndPart(I, left + 1 , mid + 1, e) );
}

int FindTree(int node, int b, int e)
{
    if(b>C2 || e<C1) return 0;
    if(b>=C1 && e<=C2)
    {
        return Find2ndPart(node, 1, 1, n);
    }
    int mid = (b+e)/2;
    int left = 2*node;
    return max(FindTree(left , b, mid), FindTree(left + 1, mid + 1, e));
}

int main()
{
    //READ();
    int test;
    scan(test);

    rep1(t,test)
    {
        scan(n);
        scan(q);

        rep1(i,n)
        {
            rep1(j,n)
            {
                scan(grid[i][j]);
            }
        }

        initTree(1,1,n);
        printf("Case %d:\n",t);
        while(q--)
        {
            int I, J, S;
            scan(I);
            scan(J);
            scan(S);
            R1 = I;
            C1 = J;
            R2 = I+S-1;
            C2 = J+S-1 ;
            int ans = FindTree(1,1,n);
            printf("%d\n",ans);
        }
    }
}
