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
#define mx 1005
#define sz 100005
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
	if(b>=from && e<=to) return tree[node].sum + (e-b+1)*carry;

	int mid = (b+e)>>1;
	int left = node<<1;
	LL ret = 0 ;

	ret+= query(left , b , mid , from  , to , carry+tree[node].acw);
	ret+= query(left|1 , mid+1 , e, from, to, carry + tree[node].acw );
	return ret;
}

void update(int node, int b, int e , int from , int to , LL w)
{
	if(b>to || e<from ) return ;
	if(b>=from && e<=to)
	{
		tree[node].sum += (e-b+1)*w;
		tree[node].acw += w;
		return;
	}

	int left = node<<1;
	int mid = (b+e)>>1;
	update(left , b, mid, from, to , w);
	update(left|1 , mid+1, e, from, to, w);

	tree[node].sum = tree[left].sum + tree[left|1].sum + (e-b+1)*tree[node].acw;
}

int main()
{
	//READ();
	int test;
	scan(test);
	char arr[sz];
	for(int t  = 1; t<= test; t++ )
	{
		for(int i = 0 ; i<=3*sz ; i++ )
			tree[i].sum = tree[i].acw = 0;

		scanf("%s",arr);
		int j;
		for(j = 0 ; arr[j]!='\0' ; j++);

		int n = j;

		for(int i = 0 ; i<=3*(n+1) ; i++ )
			tree[i].sum = tree[i].acw = 0;

		int q;
		scan(q);

		printf("Case %d:\n",t);
		while(q--)
		{
			int a,b;
			char ch;
			scanf(" %c",&ch);
			if(ch == 'I')
			{
				scan(a);scan(b);
				update(1,1,n,a, b, 1);
			}
			else
			{
				scan(a);
				int ans = query(1,1,n,a,a,0);
				char temp = arr[a-1];
				if(ans%2)
				{
					if(temp =='0')
						printf("1\n");
					else
						printf("0\n");
				}
				else
				{
					printf("%c\n",temp);
				}
			}
		}
	}
}
