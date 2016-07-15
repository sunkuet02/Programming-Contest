#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define infinite 200000
using namespace std;
/* This function makes a Tree to return the minimum value in a certain Range */
int Tree[3*200000],Arr[200005];

void build_Tree(int node,int b,int e )
{
    if(b==e)
    {
        Tree[node] = Arr[b];
        return ;
    }
    int x,y;
    build_Tree(2*node,b,(b+e)/2); // 2*node for left child .. nodenum= 2*x;
    build_Tree(2*node +1,((b+e)/2)+1,e);   // 2*node for right child .. nodenum= 2*x+1 ;
    Tree[node] = (Tree[node*2]*Tree[node*2+1]);
}
int queueri_Tree(int b,int e,int i,int j,int node)
{
    if(b>j || e<i)
        return 1;
    //cout<<Tree[node]<<endl;
    if(b>=i && e<=j){
           // cout<<Tree[node]<<"*"<<endl;;

        return Tree[node];
    }
    int x,y;
    x = queueri_Tree(b,(b+e)/2,i,j,2*node);
    y = queueri_Tree((b+e)/2+1,e,i,j,2*node+1);
    //cout<<x<<" "<<y<<endl;
    return x*y;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if (i > e || i < b)   return;
    if (b >= i && e <= i)
    {
        Tree[node] = newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    Tree[node]=Tree[Left]*Tree[Right];
}

int main()
{
    int n,q;
     //freopen("input.txt","r",stdin);
    int A,r;

    while(scanf("%d %d",&A,&r)!=EOF)
    {

        for(int i = 1; i<=A; i++)
        {
            int a;
            scanf("%d",&a);
            if(a==0)
                Arr[i] = 0;
            else if(a>0)
                Arr[i] = 1;
            else
                Arr[i] = -1;
        }
        build_Tree(1,1,A);

        char ch;
        for(int j = 0;j<r;j++)
        {

            int r1,r2;

            cin>>ch>>r1>>r2;


            if(ch=='C')
            {

                if(r2>0)
                    r2 = 1;
                else if(r2<0)
                    r2 = -1;
                update(1,1,A,r1,r2);

            }
            else if(ch=='P')
            {
                int x = queueri_Tree(1,A,r1,r2,1);


                if(x==0)
                    cout<<0;
                else if(x>0)
                    cout<<"+";
                else
                    cout<<"-";

            }

        }
        cout<<endl;


    }

}
