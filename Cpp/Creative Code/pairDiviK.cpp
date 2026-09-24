#include <bits/stdc++.h>

using namespace std;
int n, m, k;
long long ans;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> cnt(k, 0);
  long long pairs = 0;
  auto add = [&](int x)
  {
    int r = x % k;
    int need = (k - r) % k;
    pairs += cnt[need];
    cnt[r]++;
  };

  auto t = [&](int x)
  {
    int r = x % k;
    int need = (k - r) % k;
    cnt[r]--;
    pairs -= cnt[need];
  };
  for (int i = 0; i < m; i++)
    add(a[i]);
  ans = pairs;
  for (int i = m; i < n; i++)
  {
    t(a[i - m]);
    add(a[i]);
    if (pairs > ans) ans = pairs;
  }
  cout << ans;
  return 0;
}
