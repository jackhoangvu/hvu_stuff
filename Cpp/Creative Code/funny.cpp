#include <bits/stdc++.h>

using namespace std;
int T, k;

long long dem(long long x, int k)
{
  if (x < 100) return 0;
  long long cnt = 0;
  for (int duoi = 0; duoi <= 99; duoi++)
  {
    if (duoi % k == 0)
    {
      long long dau = 100 + duoi;
      if (duoi == 0) dau = 100;
      if (dau > x) continue;
      cnt += (x - dau) / 100 + 1;
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> k;
  while (T--)
  {
    long long a, b;
    cin >> a >> b;
    cout << dem(b,k) - dem(a-1, k) << "\n";
  }
  return 0;
}
