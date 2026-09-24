#include <bits/stdc++.h>
using namespace std;
int n;
long long x;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> x;
  int cur = 1;
  int max_ = 1;
  for (int i = 2; i <= n; i++)
  {
    long long y;
    cin >> y;
    if (y == x) cur++;
    else
    {
      max_ = max(max_, cur);
      cur = 1;
    }
    x = y;
  }
  max_ = max(max_, cur);
  cout << max_;
  return 0;
}
