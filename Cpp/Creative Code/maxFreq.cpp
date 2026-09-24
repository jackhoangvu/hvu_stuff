#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  unordered_map<long long, int> freq;
  freq.reserve(n * 2);
  freq.max_load_factor(0.7f);

  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    freq[x]++;
  }

  int maxF = 0;
  for (auto &p : freq)
  {
    maxF = max(maxF, p.second);
  }

  long long sum = 0;
  for (auto &p : freq)
  {
    if (p.second == maxF)
    {
      sum += p.first;
    }
  }

  cout << sum;
  return 0;
}
