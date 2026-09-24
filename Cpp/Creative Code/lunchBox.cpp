#include <bits/stdc++.h>

using namespace std;
int n, m, a[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a+m);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] <= n) {
      n -= a[i];
      ans++;
    }
    else break;
  }
  cout << ans;

  return 0;
}
