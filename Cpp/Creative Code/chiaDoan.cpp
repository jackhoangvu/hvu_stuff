#include <bits/stdc++.h>

using namespace std;
long long n, s, a[10000005];
long long cnt = 1, cur = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (cur + a[i] <= s)
    {
      cur += a[i];
    }
    else
    {
      cnt++;
      cur = a[i];
    }
  }

  cout << cnt;

  return 0;
}
