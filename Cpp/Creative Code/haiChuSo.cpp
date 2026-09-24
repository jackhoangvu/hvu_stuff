#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long cnt[3] = {0};
  for (long long i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x % 3]++;
  }
  long long ans =
      cnt[0] * (cnt[0] - 1) / 2 +
      cnt[1] * cnt[2];
  cout << ans;
  return 0;
}
