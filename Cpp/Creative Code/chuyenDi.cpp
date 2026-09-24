#include <bits/stdc++.h>
using namespace std;
long long T, n, a, b, c;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--)
  {
    cin >> n >> a >> b >> c;
    long long tong = a + b + c;
    long long f = n / tong;
    long long r = n % tong;
    long long ans = f * 3;
    if (r > 0)
    {
      if (r <= a)
      {
        ans += 1;
      }
      else if (r <= a + b)
      {
        ans += 2;
      }
      else
      {
        ans += 3;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
