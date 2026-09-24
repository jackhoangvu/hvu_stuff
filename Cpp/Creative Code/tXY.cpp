#include <bits/stdc++.h>

using namespace std;
long long n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long sqrt_n = sqrt(n);
  long long ans = 0;
  for (long long i = 1; i <= sqrt_n; i++)
  {
    ans += n/i;
  }
  ans = 2 * ans - (sqrt_n * sqrt_n);
  cout << ans;
  return 0;
}
