#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXP = 31623;
int T;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  vector<bool> isPrime(MAXP + 1, true);
  vector<int> pr;
  isPrime[0]=isPrime[1]=false;
  for (int i= 2; i<= MAXP; i++)
  {
    if (isPrime[i])
    {
      pr.push_back(i);
      if (1ll*i * i<= MAXP)
      {
        for (ll j = (ll)i * i; j <= MAXP; j += i) isPrime[j] = false;
      }
    }
  }
  while (T--)
  {
    ll a, b;
    cin>>a>>b;
    unordered_map<ll, ll> mp;
    ll x = a;
    for (int p : pr)
    {
      if ((ll)p * p > x) break;
      while (x % p == 0)
      {
        mp[p]++;
        x /= p;
      }
    }
    if (x > 1) mp[x]++;
    x = b;
    for (int p : pr)
    {
      if ((ll)p * p > x) break;
      while (x % p == 0)
      {
        mp[p]++;
        x /= p;
      }
    }
    if (x > 1) mp[x]++;
    ll result = 1;
    for (auto &it : mp) result *= (it.second + 1);
    cout << result << '\n';
  }
  return 0;
}
