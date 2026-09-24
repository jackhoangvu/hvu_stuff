#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<bool> seen(n+1,false);
  for (int i = 0; i < n; i++) {
    long long x; cin >> x;
    if (0<=x&&x<=n) seen[x] = true;
  }
  for (int i = 0; i <= n; i++) {
    if (!seen[i]) {
      cout << i;
      break;
    }
  }
  return 0;
}
