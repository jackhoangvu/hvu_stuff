#include <bits/stdc++.h>
using namespace std;
int N, a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> a >> b;
  vector<int> f(N+1);
  for (int i = 1; i <= N; i++) f[i] = 1;
  for (int i = 2; i <= N; i++)
    if (f[i]==1)
      for (int j = i; j <= N; j += i)
        f[j]*=i;
  vector<int> cnt(N+1);
  int ans = 0;
  for (int i = a; i <= b; i++) {
    cnt[f[i]]++;
    ans = max(ans,cnt[f[i]]);
  }
  cout << ans;
  return 0;
}
