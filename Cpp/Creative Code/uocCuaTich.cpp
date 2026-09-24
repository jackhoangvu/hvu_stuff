#include <bits/stdc++.h>
using namespace std;
int n, a[105];
using ll = long long;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  unordered_map<ll, ll> cnt;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    for (ll d = 2; d * d <= x; d++)
    {
      if (x % d == 0)
      {
        ll c = 0;
        while (x % d == 0)
        {
          x /= d;
          c++;
        }
        cnt[d] += c;
      }
    }
    if (x > 1)
    {
      cnt[x]++;
    }
  }
  ll ans = 1;
  for (auto &it : cnt)
  {
    ll e = it.second;
    ans = (ans *(e+1))%123456789;
  }
  cout << ans;
  return 0;
}
