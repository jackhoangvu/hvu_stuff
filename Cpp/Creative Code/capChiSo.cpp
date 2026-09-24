#include <bits/stdc++.h>
using namespace std;
int n, k;
long long cnt[15];
bool isP[15];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  isP[2] = isP[3] = isP[5]=isP[7]=true;
  long long cur = 0;
  long long ans = 0;
  cnt[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    int a;
    cin >> a;
    cur= (cur + a) % k;
    for (int rem = 0; rem < k; rem++)
    {
      int t = (cur-rem + k) % k;
      if (isP[t]) ans += cnt[rem];
    }
    cnt[cur]++;
  }
  cout << ans;
  return 0;
}
