#include <bits/stdc++.h>

using namespace std;
long long n, a[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int max = 0;
  int cur = 0;
  long long before = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];

    if (a[i] == 0)
    {
      cur = 0;
    }
    else
    {
      if (cur > 0 && ((a[i] > 0 && before > 0) || (a[i] < 0 && before < 0)))
      {
        cur++;
      }
      else
      {
        cur = 1;
      }
    }

    if (cur > max)
    {
      max = cur;
    }
    before = a[i];
  }

  cout << max;

  return 0;
}
