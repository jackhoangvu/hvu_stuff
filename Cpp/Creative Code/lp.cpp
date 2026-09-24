#include <bits/stdc++.h>

using namespace std;
int x, y;
long long m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y;
  cin >> m;
  cout << (m/x) + (m/y) - 2* (m/ lcm(1LL*x, 1LL*y));
  return 0;
}
