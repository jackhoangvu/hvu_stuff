#include <bits/stdc++.h>

using namespace std;
long long x, y, z, t, e;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y >> z >> t >> e;

  const long long INF = 1e18;
  long long best = INF;
  long long a1 = 0, a2 = 0, a3 = 0, a4 = 0;

  long long max50 = min(t, e / 50);
  for (long long x4 = max50; x4 >= 0 && x4 >= max50 - 1000; --x4)
  {
    long long remain = e - 50 * x4;
    if (remain < 0)
      continue;

    long long x3 = min(z, (remain / 20));
    remain -= 20 * x3;

    long long x2 = min(y, remain / 10);
    remain -= 10 * x2;

    if (remain % 5 != 0)
      continue;
    long long x1 = remain / 5;
    if (x1 > x)
      continue;

    long long total = x1 + x2 + x3 + x4;
    if (total < best)
    {
      best = total;
      a1 = x1;
      a2 = x2;
      a3 = x3;
      a4 = x4;
    }
  }

  if (best == INF)
  {
    cout << -1;
  }
  else
  {
    cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << best;
  }
  return 0;
}
