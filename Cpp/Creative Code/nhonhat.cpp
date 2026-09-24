#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<bool> b(n);
  for (int i = 0; i < n; i++)
  {
    long long a;cin>>a;
    if (a >= 0 && a <= n) {
      b[a] = true;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!b[i]) {
      cout << i;
      return 0;
    }
  }

  return 0;
}
