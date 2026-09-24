#include <bits/stdc++.h>

using namespace std;
int n, a[1003];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  map<int, int> d;
  for (int i = 0; i < n; i++)
  {
    d[a[i]]++;
  }
  for (auto [x, y] : d) {
    if (y == 2) {
      cout << x << "\n";
    }
  }
  return 0;
}
