#include <bits/stdc++.h>
using namespace std;
int n;
long long a[105],dmax=0;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++) cin>>a[i];
  bool b = true;
  for (int i = 1; i < n; i++)
  {
    if (a[i] != a[0])
    {
      b= false;
      break;
    }
  }
  if (b){cout<<0;return 0;}
  for (int i = 1; i < n; i++)
  {
    dmax = gcd(dmax,llabs(a[i]-a[0]));
  }
  cout << dmax;
  return 0;
}
