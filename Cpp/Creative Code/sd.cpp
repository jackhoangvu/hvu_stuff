#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  long long k = n / 9;
  long long ans = 9 * k * (k + 1) / 2;
  cout << ans;
  return 0;
}
