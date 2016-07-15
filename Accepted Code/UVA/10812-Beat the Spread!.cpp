#include<iostream>
using namespace std;
int main()
{
	unsigned int sum,diff,a,b,test,i;
	cin>>test;
	for(i=1;i<=test;i++)
	{
		cin>>sum>>diff;
		if(diff>sum || (sum+diff)%2==1)
		cout<<"impossible"<<endl;
		else
		{
			a=(sum+diff)/2;
			b=sum-a;
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}
