#include <bits/stdc++.h>

using namespace std;
int n, k;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  vector<long long> a(n);
  unordered_map<long long, long long> cnt;
  for (long long i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++)
  {
    long long r = a[i] % k;
    long long n = (k - r) % k;
    ans += cnt[n];
    cnt[r]++;
  }
  cout << ans;
  return 0;
}
