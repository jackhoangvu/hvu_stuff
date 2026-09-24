#include <bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);


  cin >> n >> m;
  vector<long long> a(n), b(m);
  long long sa = 0, sb = 0;
  for (auto &x : a) cin >> x, sa += x;
  for (auto &x : b) cin >> x, sb += x;
  long long D = sa - sb;
  long long ans = llabs(D);
  for (long long x : a)
    for (long long y : b)
      ans = min(ans, llabs(D - 2 * (x - y)));
  if (n >= 2 && m >= 2)
  {
    vector<long long> B;
    for (int i = 0; i < m; i++)
      for (int j = i + 1; j < m; j++)
        B.push_back(2 * (b[i] + b[j]));
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        long long A = 2 * (a[i] + a[j]);
        long long need = A - D;
        auto it = lower_bound(B.begin(), B.end(), need);
        if (it != B.end())
          ans = min(ans, llabs(D - (A - *it)));
        if (it != B.begin())
          ans = min(ans, llabs(D - (A - *prev(it))));
        if (!ans)
          break;
      }
      if (!ans)
        break;
    }
  }

  cout << ans;
}
