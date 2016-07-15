#include<bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);
int setbit(int N,int pos) { return N = N|(1<<pos); }
int resetbit(int N, int pos){ return N = N & ~(1<<pos) ;}
bool checkbit(int N,int pos) { return (bool) (N & 1<<pos) ;}

#define mx 110
#define INF 214000000
using namespace std;

int arr[15][mx];
int dp[15][mx];
int path[15][mx];
int m,n;

int tsp(int i, int j)
{
    if(j>n)  return 0;
    int next[] = {i-1, i, i+1};
    if(next[0]==0) next[0] = m;
    if(next[2]==m+1) next[2] = 1;
    if(dp[i][j]!=INF) return dp[i][j];
    //cout<<next[0]<<ends<<next[1]<<ends<<next[2]<<endl;
    for(int k = 0 ; k< 3; k++ )
    {
        int value = arr[i][j] + tsp(next[k],j+1);
        if(dp[i][j]> value || (dp[i][j]==value && path[i][j]>next[k]))
        {
            dp[i][j] = value;
            path[i][j] = next[k];
        }
    }
    return dp[i][j];
}
int main()
{

    //freopen("input.txt","r",stdin);
    while(scanf("%d %d",&m, &n )!=EOF)
    {
        rep1(i,m) rep1(j,n) scan(arr[i][j]);

        rep0(i,12) rep0(j,mx-2) dp[i][j] = INF;
        memset(path,200,sizeof(path));

        int minimum = tsp(1,1);
        int point = 1;
        for(int i = 2; i<=m; i++ )
        {
            int ret = tsp(i,1);
            if(ret<minimum)
            {
                minimum = ret;
                point = i;
            }

        }

        cout<<point;
        rep1(i,n-1)
        {
            cout<<" "<<path[point][i];
            point = path[point][i];
        }
        cout<<endl<<minimum<<endl;;

    }

}

//vector<int>route,temproute;
//
//void findRoute(int i, int j)
//{
//    if(j==1) return;
//    route.push_back(path[i][j]);
//    findRoute(path[i][j],j-1);
//}
//
//int main()
//{
//    int m,n;
//    freopen("input.txt","r",stdin);
//    while(scanf("%d %d",&m, &n )!=EOF)
//    {
//        rep1(i,m) rep1(j,n) scan(arr[i][j]);
//
//        rep0(i,m) dp[i][0] = 0,path[i][1] = i;
//        rep1(i,n) dp[0][i] = arr[m][i];
//        rep1(i,n) dp[m+1][i] = arr[1][i];
//
//        rep1(j,n)
//        {
//            rep1(i,m)
//            {
//                int a = i-1;
//                if(dp[i-1][j-1] > dp[i][j-1])
//                    a = i;
//                if(dp[i+1][j-1] < dp[i][j-1] && dp[i-1][j-1] > dp[i][j-1])
//                    a = i+1;
//                dp[i][j] = arr[i][j] +  min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i+1][j-1]));
//                path[i][j] = a;
//                if(i==1)
//                {
//                    dp[m+1][j] = dp[i][j];
//                }
//                else if(i==m)
//                {
//                    dp[0][j] = dp[i][j];
//                }
//                if(a==0)
//                {
//                    if(dp[i][j-1]+arr[i][j]==dp[i][j])
//                        path[i][j]=i;
//                    else
//                        path[i][j] = m;
//                }
//                else if(a==m+1)
//                    path[i][j] = 1;
//                else if(i==m)
//                {
//                    if(dp[m+1][j-1]+arr[i][j]==dp[i][j])
//                        path[i][j] = 1;
//                }
//
//            }
//
//        }
//        rep0(i,m+2)
//        {
//            rep0(j,n+2)
//                printf("%2d + %2d ",dp[i][j],path[i][j]);
//            cout<<endl;
//        }
//        int minimum = dp[1][n];
//        int point   = 1;
//        rep(i,2,m)  if(dp[i][n] < minimum  )  {minimum = dp[i][n]; point = i; }
//
//
//        route.push_back(point);
//        findRoute(point,n);
//
//        cout<<route[route.size()-1];
//        for(int i = route.size()-2 ; i>=0; i--)
//        {
//            cout<<" "<<route[i];
//        }
//        cout<<endl;
//        cout<<minimum<<endl;
//
//        route.clear();
//    }
//
//}


