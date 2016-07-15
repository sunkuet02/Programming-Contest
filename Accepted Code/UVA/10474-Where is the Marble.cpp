#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int binary_sach(int item)
{
    int low_bound=0,up_bound=v.size()-1;
    int mid=(low_bound+up_bound)/2;
    for(;;)
    {
        if(item==v[mid])
        {
            while(item==v[mid])
            {
                mid--;
            }
            return mid+1;
        }
        else if(item<v[mid])
        {
            up_bound=mid-1;
        }
        else
            low_bound=mid+1;
        mid=(low_bound+up_bound)/2;
        if(up_bound<low_bound)
        {
            return -1;
        }
    }
    return -1;
}
int main()
{
    int a,b,c;
    for(int j=1;; j++)
    {
        cin>>a>>b;
        if(a==0 && b==0 ) break;
        cout<<"CASE# "<<j<<":"<<endl;
        for(int i=1; i<=a; i++)
        {
            cin>>c;
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        for(int i=1; i<=b; i++)
        {
            int item,r;
            cin>>item;
            r=binary_sach(item) ;
            if(r==-1) cout<<item<<" not found"<<endl;
            else cout<<item<<" found at "<<(r+1)<<endl;
        }
        v.clear();
    }
    return 0;
}
