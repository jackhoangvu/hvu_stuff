#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5 + 5;
ll n, a[MAX];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<ll> ans;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    if (x >= 5 && (x - 5) % 3 == 0)
    {
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
  return 0;
}
