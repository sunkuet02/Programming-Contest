#include <bits/stdc++.h>
#define mx 100000
using namespace std;

int arr[mx];
struct node
{
    int propagation , sum ;
} Tree[mx*3];

int buildTree(int node, int b, int e)
{
    if(b==e)
    {
        return Tree[node].sum = arr[b];
    }

    int left = buildTree(node*2,b,(b+e)/2);
    int right = buildTree(node*2 + 1,((b+e)/2 )+1,e);

    return Tree[node].sum = left+right;
}

void updateTree(int node , int b, int e, int i, int j, int value)
{
    if(i>e || j<b)
        return;
    if(b >= i && j >=e)
    {
        Tree[node].sum += value*(e-b+1);
        Tree[node].propagation +=value;
        return;
    }

    updateTree(node*2 , b, (b+e)/2 , i, j, value);
    updateTree(node*2 + 1 , ((b+e)/2) +1 , e, i, j, value);
    Tree[node].sum = Tree[node*2].sum + Tree[(node*2)+1].sum + Tree[node].propagation * (e-b+1);
    return;
}

int queryTree(int node , int b, int e, int i, int j, int  carry)
{
    if(i>e || j<b) return 0;

    if(b>=i && e<=j)
    {
        return Tree[node].sum + carry*(e-b+1);
    }

    int left = queryTree(node*2 , b, (b+e)/2 , i, j, carry+Tree[node].propagation);
    int right = queryTree(node*2 + 1 , ((b+e)/2) +1 , e, i, j, carry+Tree[node].propagation);

    return left+right;
}

int main()
{
    int n;

    buildTree(1,1,n);

    return 0;
}
