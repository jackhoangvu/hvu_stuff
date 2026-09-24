#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  unordered_map<int, int> cnt;
  cnt.reserve(n * 2);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }
  long long keep = 0;
  for (auto &p : cnt)
  {
    int value = p.first;
    int frequency = p.second;
    if (frequency >= value)
    {
      keep += value;
  }
}
  cout << n - keep;
  return 0;
}
