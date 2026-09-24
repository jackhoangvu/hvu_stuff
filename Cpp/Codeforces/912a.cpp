#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t a,b,x,y,z;
  cin>>a>>b>>x>>y>>z;

  int64_t ny=2*x+y;
  int64_t nb=3*z+y;

  int64_t ey=max((int64_t)0, ny-a);
  int64_t eb=max((int64_t)0, nb-b);
  //   2 2 1
  //-> 2*x + 2*(y+z) + z
  cout<<ey+eb;
  return 0;
}
