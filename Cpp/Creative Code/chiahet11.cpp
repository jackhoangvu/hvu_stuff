#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long cnt[10] = {0};
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }
  long long ans = 0;

  for (int d = 1; d <= 9; d++) ans += cnt[d] / 2;
  cout << ans << '\n';
  return 0;
}
