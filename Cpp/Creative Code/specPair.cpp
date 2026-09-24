#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long ans = 0;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> spec;
  for (int d = 1; d <= 9; d++) {
    long long x = 0;
    while (true) {
      x=x*10+ d;
      if (x > 2000000) break;
      spec.push_back((int)x);
    }
  }
  vector<int> cnt(1000005,0);
  for (int i = 0; i < n; i++)
  {
    for (int s: spec)
    {
      int l= s- a[i];
      if (l >= 0 && l <= 1000000) {
        ans+= cnt[l];
      }
    }
    cnt[a[i]]++;
  }
  cout << ans;
  return 0;
}
