#include <bits/stdc++.h>

using namespace std;
long long n, a[100006];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int k = 0; k < n; k++) {
    unordered_set<int> b;
    for (int j = 0; j < n; j++) {
      int c = a[k] - a[j];
      if (j == k) continue;
      if (b.count(c)) {cout<<"Yes\n";return 0;}
      b.insert(a[j]);
    }
  }
  cout << "No\n";
  return 0;
}
