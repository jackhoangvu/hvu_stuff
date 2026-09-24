#include <bits/stdc++.h>

using namespace std;
long long n,m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<long long> a(n+1), b;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> m;
  b.resize(m+1);
  for (int i = 1; i <= m; i++) cin >> b[i];
  vector<long long> p0a, p0b;
  p0a.push_back(1); p0b.push_back(1);
  for (int i = 1; i <= n; i++) if (!a[i]) p0a.push_back(i);
  for (int i = 1; i <= m; i++) if (!b[i]) p0b.push_back(i);
  vector<long long> s1a(n+2,0), s1b(m+2,0);
  for (int i = n; i >= 1; i--) s1a[i] = s1a[i+1] + a[i];
  for (int i = m; i >= 1; i--) s1b[i] = s1b[i+1] + b[i];
  long long ans = 0, lim = min((long long)p0a.size(), (long long)p0b.size());
  for (int z = 0; z < lim; z++) ans = max(ans, z + min(s1a[p0a[z]], s1b[p0b[z]]));
  cout << ans;
  return 0;
}
