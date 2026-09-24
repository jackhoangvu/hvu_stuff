#include <bits/stdc++.h>
using namespace std;
long long l, r;
long long ans = 0;
static vector<int> findPrime(int limit)
{
  vector<bool> isPrime(limit + 1, true);
  isPrime[0] = false;
  if (limit >= 1)
    isPrime[1] = false;
  for (int i = 2; 1LL * i * i <= limit; i++)
  {
    if (!isPrime[i])
      continue;
    for (long long j = 1LL * i * i; j <= limit; j += i)
    {
      isPrime[(int)j] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= limit; i++)
  {
    if (isPrime[i])
      primes.push_back(i);
  }
  return primes;
}
static bool notSquare(long long x, const vector<int> &primes)
{
  for (int p : primes)
  {
    long long pp = 1LL * p * p;
    if (pp > x)
      break;
    if (x % pp == 0)
      return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> r;
  if (l > r)
  {
    return 0;
  }
  int nums = (int)(r - l + 1);
  long long soCap = 1LL * nums * (nums - 1) / 2;
  int lim = (int)sqrt((long double)r);
  vector<int> primes = findPrime(lim);
  vector<long long> sqfree;
  sqfree.reserve(nums);
  for (long long v = l; v <= r; v++)
  {
    if (notSquare(v, primes))
    {
      sqfree.push_back(v);
    }
  }
  long long good = 0;
  int m = (int)sqfree.size();
  for (int i = 0; i < m; i++)
  {
    for (int j = i + 1; j < m; j++)
    {
      if (gcd(sqfree[i], sqfree[j]) == 1)
      {
        good++;
      }
    }
  }
  long long bad = soCap - good;
  cout << bad;
  return 0;
}
