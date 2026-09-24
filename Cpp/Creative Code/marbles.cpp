#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  long long k = sum / n;
  long long r = sum % n;
  long long ans = 0;
  for (int i = 0; i < n - r; i++)
    if (a[i] > k)
      ans += a[i] - k;
  for (int i = n - r; i < n; i++)
    if (a[i] > k + 1)
      ans += a[i] - (k + 1);
  cout << (r?1:0) << "\n";
  cout << ans << "\n";
  return 0;
}
