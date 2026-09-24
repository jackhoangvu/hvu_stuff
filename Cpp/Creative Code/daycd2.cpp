#include <bits/stdc++.h>
using namespace std;

int n, a[200005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  if (n <= 2)
  {
    cout << n;
    return 0;
  }

  int ans = 2;
  int len = 2;
  int diff = a[1] - a[0];
  for (int i = 2; i < n; i++)
  {
    int new_diff = a[i] - a[i - 1];

    if (new_diff == diff)
    {
      len++;
    }
    else
    {
      len = 2;
      diff = new_diff;
    }
    ans = max(ans, len);
  }

  cout << ans;
  return 0;
}
