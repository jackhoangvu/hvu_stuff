#include <bits/stdc++.h>

using namespace std;
int n, i;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<long long> a(n+1);
  for (int j = 1; j <= n; j++) {
    cin >> a[j];
  }
  cin >> i;
  long long max1=LLONG_MIN, max2 = LLONG_MIN;
  for (int j = 1; j < i; j++) {
    if (a[j]%2==0) max2 = max(max2, a[j]);
    else max1 = max(max1, a[j]);
  }
  if (a[i] % 2 == 0) {
    if (max1 == LLONG_MIN) cout << "IMPOSSIBLE";
    else cout << a[i] + max1;
  } else {
    if (max2 == LLONG_MIN) cout << "IMPOSSIBLE";
    else cout << a[i] + max2;
  }
  return 0;
}
