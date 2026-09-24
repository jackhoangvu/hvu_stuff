#include <bits/stdc++.h>

using namespace std;
int n, m;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int limit = n + m + 2;
  vector<bool> used(limit, false);

  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    if (0 <= x && x < limit)
      used[x] = true;
  }

  for (int i = 0; i < m; i++)
  {
    long long x;
    cin >> x;
    if (0 <= x && x < limit)
      used[x] = true;
  }

  for (int i = 0; i < limit; i++)
  {
    if (!used[i])
    {
      cout << i;
      break;
    }
  }
  return 0;
}
