#include <bits/stdc++.h>

using namespace std;
int n, x;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  vector<int> a(n);
  if (x == 0)
  {
    return 0;
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (a[i] % x == 0)
    {
      ans = min(ans, a[i]);
    }
  }
  cout << ans;
  return 0;
}
