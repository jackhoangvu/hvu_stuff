#include <bits/stdc++.h>

using namespace std;
long long n;
long long k;
long long h[200005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  sort(h, h + n);
  long long ans = 0;
  int i = 0;
  int j = (n + 1) / 2;
  while (i < (n + 1) / 2 && j < n)
  {
    if (abs(h[j] - h[i]) >= k)
    {
      ans++;
      i++;
    }
    j++;
  }
  cout << ans;
  return 0;
}
