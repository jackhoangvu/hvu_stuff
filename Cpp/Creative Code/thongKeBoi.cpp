#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], b[1000005], ans[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (!(cin >> n))
    return 0;

  int maxVal = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[a[i]]++;
    if (a[i] > maxVal)
      maxVal = a[i];
  }
  for (int i = 1; i <= maxVal; i++)
  {
    if (b[i] > 0)
    {
      for (int j = i; j <= maxVal; j += i)
      {
        ans[i] += b[j];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << ans[a[i]] << (i == n - 1 ? "" : " ");
  }

  return 0;
}
