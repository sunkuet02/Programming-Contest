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
#define sz 1005
#define mod 1000000007
using namespace std;

const int BUFSIZE = 1 << 16; char BUFFER[BUFSIZE + 5]; int REM = 0, POS = 0;

char GETCHAR()
{if (REM <= 0){POS = 0; REM = fread(BUFFER, 1, BUFSIZE, stdin);
 if (REM <= 0) return EOF;}
 --REM; return BUFFER[POS++];
}
void GETINT(int &VAL)
{
	VAL = 0; char C = EOF; while (C != '-' && !isdigit(C)) C = GETCHAR();
	bool NEG = C == '-'; if (NEG) C = GETCHAR();
	while (isdigit(C)) { VAL = VAL * 10 + C - '0'; C = GETCHAR(); }
	if (NEG) VAL = -VAL;
}

int Tree[sz][sz];
int n,max_x = 1001, max_y=1001 ;
bool islisted [sz][sz];

int query(int x, int y)
{
    int sum = 0;
    while(x)
    {
        int y1 = y;
        while(y1)
        {
            sum+= Tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x-= (x&-x);
    }
    return sum;
}

void update(int x, int y, int val)
{
    while(x<=max_x)
    {
        int y1 = y;
        while(y1<=max_y)
        {
            Tree[x][y1] += val;
            y1+= (y1 & -y1);
        }
        x+= (x&-x);
    }
}


int main()
{
    //READ();
    int test;
    GETINT(test);
    rep1(t,test)
    {
        memset(Tree, 0 , sizeof(Tree));
        memset(islisted , false , sizeof(islisted));

        int q;
        GETINT(q);

        printf("Case %d:\n",t);
        while(q--)
        {
            int type, x, y;
            GETINT(type);GETINT(x);GETINT(y);
            if(type ==0 )
            {
                if(!islisted[x][y])
                    update(1+x,1+y,1);
                islisted[x][y] = true;
            }
            else if(type == 1)
            {
                int x1, y1;
                GETINT(x1);GETINT(y1);

                int tot = query(1+x1,1+y1) + query(x,y) - query(1+x1,y) - query(x,1+y1)  ;
                printf("%d\n",tot);
            }

        }
    }

}

inline int gcd(int a, int b) { int r; while(b!=0){ r = a%b ; a = b; b =r ; } return a; }
using namespace std;

struct node
{
	LL sum ;
	LL acw ;
}tree[sz*3];

int n;

LL query(int node , int b, int e, int from, int to, LL carry = 0)
{
	if(b>to || e< from ) return 0;
	if(b>=from && e<=to) return tree[node].sum ;

	int mid = (b+e)>>1;
	int left = node<<1;

	if(tree[node].acw!=-1)
    {
        tree[left].sum = (mid - b + 1)* tree[node].acw;
        tree[left|1].sum = (e - mid) * tree[node].acw;
        tree[left].acw = tree[left|1].acw = tree[node].acw;
        tree[node].acw = -1;
    }

	LL ret = 0 ;

	ret+= query(left , b , mid , from  , to );
	ret+= query(left|1 , mid+1 , e, from, to );

	tree[node].sum = tree[left].sum + tree[left|1].sum ;
	return ret;
}

void update(int node, int b, int e , int from , int to , LL val)
{
	if(b>to || e<from ) return ;
	if(b>=from && e<=to)
	{
		tree[node].sum = (e-b+1)*val;
		tree[node].acw = val;
		return;
	}
	int left = node<<1;
	int mid = (b+e)>>1;

    if(tree[node].acw!=-1)
    {
        tree[left].sum = (mid - b + 1)* tree[node].acw;
        tree[left|1].sum = (e - mid) * tree[node].acw;
        tree[left].acw = tree[left|1].acw = tree[node].acw;
        tree[node].acw = -1;
    }


	update(left , b, mid, from, to , val);
	update(left|1 , mid+1, e, from, to, val);

	tree[node].sum = tree[left].sum + tree[left|1].sum ;
}

int main()
{
	//READ();
	int test;
	scan(test);
	for(int t  = 1; t<= test; t++ )
	{
	    int q;
	    scan(n);scan(q);
		for(int i = 0 ; i<=3*n ; i++ )
        {
            tree[i].sum = 0;
            tree[i].acw = -1;
        }

		printf("Case %d:\n",t);
		while(q--)
		{
			int token , i, j , v ;
			scan(token);
			scan(i);
			scan(j);
			if(token==1 )
            {
                scan(v);
                update(1,1,n,++i,++j, v);

            }
            else
            {
                int ans = query(1,1,n,++i , ++j);
                int no = j - i +1;
                if(ans %no ==0)
                {
                    printf("%d\n",ans/no);
                }
                else
                {
                    int g = gcd(ans, no);
                    printf("%d/%d\n",ans/g, no/g);
                }

            }

		}
	}
}

