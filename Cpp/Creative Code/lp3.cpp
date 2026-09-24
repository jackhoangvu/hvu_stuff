#include <bits/stdc++.h>

using namespace std;
long long x, y, z, m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y >> z;
  cin >> m;
  int Lxyz = lcm(lcm(x,y), z);
  int xy = (m/(lcm(x,y))) - (m/Lxyz);
  int xz = (m/(lcm(x,z))) - (m/Lxyz);
  int yz = (m/(lcm(y,z))) - (m/Lxyz);
  cout << xy + xz + yz;
  return 0;
}
