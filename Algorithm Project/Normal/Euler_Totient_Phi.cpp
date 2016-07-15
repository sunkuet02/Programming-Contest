#include<bits/stdc++.h>
using namespace std;
#define mx 100005

/****************** Phi where need many times*********/

int P[mx] ;
int Phi(int n)
{
    for(int i = 1 ; i<= n ; i++ )
    {
        P[i] = i;
    }

    for(int i = 2 ; i < n ; i++ )
    {
        if(P[i] == i )
        {
            for(int j = i ; j< n ; j+= i )
                P[j] -= P[j]/i;
        }
    }
}


/*******************Phi for one case **************/

int phi(int n)
{
    int result = n;
    if(n%2==0)
    {
        while(n%2==0)
            n/=2;
        result -= (result/2);
    }
    for(int i = 3 ; i<=n ; i+=2)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            result -= (result/i);
        }
    }
    if (n > 1)
        result -= result / n;
    return result;

}



int main()
{
    Phi(10005) ;
    int n;
    cin >> n ;
    cout <<P[n] << endl;
}
