#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  long long ans = 0;
  for (long long x = 1; x <= n; x++)
  {
    ans += min(k, n-x);
  }
  cout << ans;
  return 0;
}
