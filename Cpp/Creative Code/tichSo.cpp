#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n < 6) cout << 0;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  vector<int> P;
  for (int p = 2; p <= n; p++) {
    if (is_prime[p]) P.push_back(p);
  }
  long long cnt = 0;
  for (int i = 0; i < P.size(); ++i) {
    int p = P[i];
    if ((long long)p * p > n) {
      break;
    }
    int Q_max = n / p;
    for (int j = i + 1; j < P.size(); ++j) {
      int q = P[j];
      if (q > Q_max) {
        break;
      }
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
