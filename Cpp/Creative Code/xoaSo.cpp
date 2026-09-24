#include <bits/stdc++.h>

using namespace std;
int n, k, a[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = LLONG_MAX;
  int len= n-k;
  for (int i = 0; i + len - 1 < n; i++)
  {
    long long smax = a[i+len-1] - a[i];
    ans = min(ans,smax);
  }
  cout << ans;
  return 0;
}
