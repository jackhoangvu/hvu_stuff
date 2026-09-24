#include <bits/stdc++.h>

using namespace std;
int n, a[5005];

bool isPrime(long long n)
{
  if (n < 2)
    return false;
  if (n == 2 || n == 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (long long i = 5; i * i <= n; i += 6)
  {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      long long sum = a[i] + a[j];
      if (isPrime(sum))
      {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
