#include <bits/stdc++.h>

using namespace std;
int n, x;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (x == 0)
      return 0;
    cout << 1 + (x - 1) % 9 << ' ';
  }

  return 0;
}
