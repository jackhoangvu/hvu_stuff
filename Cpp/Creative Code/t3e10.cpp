#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long cnt[12] = {0};
  long long pair_cnt[22] = {0};
  long long ans = 0;
  for (int r = 0; r < n; r++)
  {
    int val = a[r];
    if (10 - val >= 0) ans += pair_cnt[10 - val];
    for (int x = 0; x <= 10; x++)
      if (cnt[x] > 0) pair_cnt[x + val] += cnt[x];
    cnt[val]++;
  }
  cout << ans << "\n";
  return 0;
}
