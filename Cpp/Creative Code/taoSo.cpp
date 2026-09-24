#include <bits/stdc++.h>
using namespace std;

int k;
long long n;
string ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k >> n;
  vector<int> d(k);
  for (int i = 0; i < k; i++)
    cin >> d[i];
  sort(d.begin(), d.end());

  if (k == 1)
  {
    cout << string((size_t)n, char('0' + d[0]));
    return 0;
  }

  long long L = 0;
  long long prev = 0;
  long long p = 1;

  while (true)
  {
    L++;
    if (p > (LLONG_MAX / k))
      p = LLONG_MAX;
    else
      p *= k;
    if (prev + p >= n)
      break;
    prev += p;
  }

  long long t = n - prev - 1;

  ans.reserve((size_t)L);

  for (int i = 0; i < L; i++)
  {
    int idx = (int)(t % k);
    ans.push_back(char('0' + d[idx]));
    t /= k;
  }

  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}
