#include <iostream>
#include <algorithm>
using namespace std;
int ar[100];
int binarySearch(int a)
{
    int low_bound=0,up_bound=a-1;
    int mid=(low_bound+up_bound)/2;
    cout<<"Enter the value do u want to search"<<endl;
    int item;
    cin>>item;
    for(int x=0; x<a; x++)

	{
		for(int y=0; y<a-1; y++)
		{
			if(ar[y]>ar[y+1])
			{
				int temp = ar[y+1];
				ar[y+1] = ar[y];
				ar[y] = temp;
			}
		}
	}
	for(int i=0;i<a;i++) cout<<" " <<ar[i];
    for(;;)
    {
        if(item==ar[mid])
        {
            return mid;
        }
        else if(item<ar[mid])
        {
            up_bound=mid-1;
        }
        else
            low_bound=mid+1;
        mid=(low_bound+up_bound)/2;
        if(up_bound<=low_bound)
        {
            if(item==ar[mid]) return mid;
            else
                 break;
        }
    }
    return -1;
}
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++) cin>>ar[i];
    int m=binarySearch(a);
    if(m==-1) cout<<"The value is not found"<<endl;
    else cout<<"The value is found at "<<m+1<<"th position"<<endl;
}
