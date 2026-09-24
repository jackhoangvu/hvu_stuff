#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100005];
  long long l, m, cnt=0;
  cin >> n >> l >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (abs(l - a[i]) <= m) cnt++;
  }
  cout << cnt;
  return 0;
}
