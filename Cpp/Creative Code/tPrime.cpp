#include <bits/stdc++.h>

using namespace std;
int n, T;

bool isPrime(int n)
{
  if (n < 2)
    return false;
  if (n == 2 || n == 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6)
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

  cin >> n >> T;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    p[i] = isPrime(a[i]);
  }
  int sum = 0;
  for (int i = 0; i < T; i++) sum += p[i];
  if (sum == 0)
  {
    cout << 0;
    return 0;
  }
  for (int i = T; i < n; i++)
  {
    sum += p[i];
    sum -= p[i - T];
    if (sum == 0)
    {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
  return 0;
}
