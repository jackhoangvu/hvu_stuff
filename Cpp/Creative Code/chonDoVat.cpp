#include <bits/stdc++.h>
using namespace std;
int n;
long long w;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  vector<long long> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  long long sumW = 0, sumV = 0;
  long long best = 0;
  int bestL = -1, bestR = -1;
  int l = 1;
  for (int r = 1; r <= n; r++)
  {
    sumW += a[r];
    sumV += b[r];
    while (sumW > w)
    {
      sumW -= a[l];
      sumV -= b[l];
      l++;
    }
    if (sumV > best)
    {
      best = sumV;
      bestL = l;
      bestR = r;
    }
  }
  if (best == 0)
  {
    cout << 0;
  }
  else
  {
    cout << best << '\n';
    cout << bestL << " " << bestR;
  }
  return 0;
}
