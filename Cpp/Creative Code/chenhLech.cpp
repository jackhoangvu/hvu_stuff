#include <bits/stdc++.h>
using namespace std;
int n, a[505], cnt = 0;
bool nt(int n) {
  if (n < 2) return false;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin>> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (nt(abs(a[i]-a[j]))) cnt++;
  cout << cnt;
  return 0;
}
