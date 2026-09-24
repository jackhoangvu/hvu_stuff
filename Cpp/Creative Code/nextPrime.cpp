#include <bits/stdc++.h>
using namespace std;

using u128 = __uint128_t;
using ll = long long;

ll mod_mul(ll a, ll b, ll mod)
{
  return (u128)a * b % mod;
}
ll mod_pow(ll a, ll d, ll mod)
{
  ll r = 1;
  while (d)
  {
    if (d & 1)
      r = mod_mul(r, a, mod);
    a = mod_mul(a, a, mod);
    d >>= 1;
  }
  return r;
}
bool isPrime(ll n)
{
  if (n < 2)
    return false;
  for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
  {
    if (n == p)
      return true;
    if (n % p == 0 && n != p)
      return false;
  }
  ll d = n - 1, s = 0;
  while ((d & 1) == 0)
  {
    d >>= 1;
    s++;
  }
  auto w = [&](ll a)
  {
    ll x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1)
      return false;
    for (int i = 1; i < s; i++)
    {
      x = mod_mul(x, x, n);
      if (x == n - 1)
        return false;
    }
    return true;
  };
  for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
  {
    if (a % n == 0)
      continue;
    if (w(a))
      return false;
  }
  return true;
}
ll nextPrime(ll n)
{
  if (n < 2)
    return 2;
  ll x = n + 1;
  if (x % 2 == 0)
    x++;
  while (!isPrime(x))
    x += 2;
  return x;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    cout << nextPrime(n) << "\n";
  }
  return 0;
}
