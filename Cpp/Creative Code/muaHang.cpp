#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long sum = 0;
  long long min_le = LLONG_MAX;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    sum += x;
    if (x % 2 != 0)
    {
      if (x < min_le)
        min_le = x;
    }
  }
  if (sum % 2 == 0) cout << sum;
  else
  {
    if (min_le != LLONG_MAX) cout << sum - min_le;
    else cout << 0;
  }
  return 0;
}
