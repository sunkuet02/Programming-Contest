/* ******************************************************
*  Md. Abdulla-Al-Sun
*  KUET, Bangladesh
****************************************************** */

#include <bits/stdc++.h>

#define scan(a) scanf("%d",&a)
#define rep0(i,n) for(int i = 0; i<n ;i++)
#define rep1(i,n) for(int i = 1; i<=n ;i++)
#define rep(i,a,b) for(int i = a; i<=b ;i++)
#define READ() freopen("input.txt","r",stdin);

#define LL long long int

using namespace std;
vector<pair< pair<int, int> , int > > v;
int Local[185];

int tower()
{
    int mxLength = 0 ;
    rep0(i,v.size())
    {
        Local[i] = v[i].second;
        //cout<<v[i].first.first<<ends<<v[i].first.second<<ends<<v[i].
        rep0(j,i)
        {
            if((v[j].first.first > v[i].first.first && v[j].first.second > v[i].first.second))
            {
                Local[i] = max(Local[i],v[i].second + Local[j]);
            }
        }
        mxLength = max (mxLength,Local[i]);
    }
    return mxLength;
}

int main()
{
    //READ();
    int n;
    int caseno = 0;
    while(scan(n)&& n )
    {
        rep1(i,n)
        {
            int a,b,c;
            scan(a);scan(b);scan(c);
            v.push_back(make_pair(make_pair(a,b),c));
            v.push_back(make_pair(make_pair(a,c),b));
            v.push_back(make_pair(make_pair(b,a),c));
            v.push_back(make_pair(make_pair(b,c),a));
            v.push_back(make_pair(make_pair(c,a),b));
            v.push_back(make_pair(make_pair(c,b),a));
        }
        sort(v.rbegin(), v.rend());
        int height = tower();

        printf("Case %d: maximum height = %d\n",++caseno,height);
        v.clear();
    }

}
