#include <bits/stdc++.h>

using namespace std;
int n, k, x[105];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x[i];
  }
  for (int i = 0; i < k; i++)
  {
    if (find(a.begin(), a.end(), x[i]) != a.end())
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  }
  return 0;
}
