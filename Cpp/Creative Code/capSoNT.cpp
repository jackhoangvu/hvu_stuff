#include <bits/stdc++.h>

using namespace std;
int l, r;
long long ans = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> r;

  int duoi = 2 * l + 1;
  int tren = 2 * r - 1;
  int n = tren;
  vector<char> p(n + 1, 1);
  if (n >= 0)
    p[0] = 0;
  if (n >= 1)
    p[1] = 0;
  for (int i = 2; 1LL * i * i <= n; i++)
  {
    if (!p[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      p[j] = 0;
  }
  for (int x = duoi; x <= tren; x++)
    ans += p[x];

  cout << ans;
  return 0;
}
