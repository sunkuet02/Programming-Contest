#include <iostream>

using namespace std;

int main()
{
  long long  n;

  long long  c,r;
  while(1)
  {
      cin>>n>>r;
      if(n ==0 && r ==0)
        break;
     c = 1;
     if(r > n-r)
        r = n-r;

    for (int x = 0; x <= r-1; x++)
    {
      c = c * (n - x) / (x + 1);

    }
    cout<<c<<endl;
  }

  return 0;
}
