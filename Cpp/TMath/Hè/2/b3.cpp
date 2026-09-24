#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,c; cin>>a>>b>>c;
  long long x,y,z; cin>>x>>y>>z;
  cout<<lcm(a+b+c,x+y+z);
  return 0;
}
