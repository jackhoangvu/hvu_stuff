#include <bits/stdc++.h>
using namespace std;
long long x, m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> m;
  long long b = 1, t = x;
  while (t)
    b *= 10, t /= 10;
  if (m < x)
  {
    cout << 0;
    return 0;
  }
  cout << (m-x)/b;
  return 0;
}
