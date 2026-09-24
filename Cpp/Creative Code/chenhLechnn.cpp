#include <bits/stdc++.h>

using namespace std;
long long n, a[200005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = LLONG_MAX;

  for (int i = 1; i < n; i++)
  {
    ans = min(ans, a[i] - a[i - 1]);
  }

  cout << ans;
  return 0;
}
