#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans= 0;
  long long maxA = *max_element(a.begin(), a.end());
  vector<long long> freq(maxA + 1, 0);
  vector<long long> cnt(maxA + 1, 0);
  vector<long long> p_cnt(maxA + 1, 0);
  for (long long i = 0; i < n; i++) freq[a[i]]++;
  for (long long d = 1; d <= maxA; d++)
    for (long long x = d; x <= maxA; x += d)
      cnt[d] += freq[x];
  for (long long d = 1; d <= maxA; d++) p_cnt[d] = cnt[d] * (cnt[d] - 1) / 2;
  for (long long d = maxA; d >= 1; d--)
    for (long long x = 2 * d; x <= maxA; x += d)
      p_cnt[d] -= p_cnt[x];
  ans = p_cnt[1];
  cout << ans;
  return 0;
}
