#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i < k; i++) sum += a[i];
  int ans = sum;
  for (int i = k; i < n; i++) sum += a[i] - a[i-k], ans = max(ans, sum);
  cout << ans << "\n";
  return 0;
}
