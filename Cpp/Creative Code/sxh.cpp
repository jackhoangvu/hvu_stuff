#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int q;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> b[i];
  unordered_map<long long, int> freq;
  freq.reserve(n * 2);
  for (int i = 0; i < n; i++) freq[a[i]]++;
  for (int i = 0; i < q; i++)
  {
    auto it = freq.find(b[i]);
    cout << (it == freq.end() ? 0 : it->second) << "\n";
  }
  return 0;
}
