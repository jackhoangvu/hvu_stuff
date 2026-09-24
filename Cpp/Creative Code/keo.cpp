#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
bool check(long long mid)
{
  long long need = 0;
  for (long long x : a)
  {
    if (x < mid)
    {
      need += mid - x;
      if (need > m) return false;
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  long long mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  long long lo = 0, hi = mx + m, ans = 0;
  while (lo <= hi)
  {
    long long mid = (lo + hi) / 2;
    if (check(mid))
    {
      ans = mid;
      lo = mid + 1;
    }
    else hi = mid - 1;
  }
  vector<long long> r(n);
  long long used = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < ans)
    {
      used += ans - a[i];
      r[i] = ans;
    }
    else
    {
      r[i] = a[i];
    }
  }
  long long rem = m - used;
  vector<int> id;
  for (int i = 0; i < n; i++)
    if (r[i] == ans) id.push_back(i);
  for (int i = 0; i < (int)id.size() && rem > 0; i++)
  {
    r[id[i]]++;
    rem--;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) cout << r[i] << "\n";
  return 0;
}
