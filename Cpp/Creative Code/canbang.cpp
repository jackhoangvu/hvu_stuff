#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], cnt;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  unordered_set<long long> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (s.count(a[i] + k) && s.count(a[i] - k)) {
      cnt++;
    }
  }
    cout << cnt;
  return 0;
}
