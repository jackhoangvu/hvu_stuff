#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--)
  {
    long long L, R, cnt = 0;
    cin >> L >> R;
    for (int d = 0; d <= 6; d++)
    {
      cnt += (R-d) / 70 + 1;
      if (L > d)
        cnt -= (L-d-1) / 70 + 1;
    }
    cout << cnt << '\n';
  }
  return 0;
}
