#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  long long ans = 0, cur = 0;
  bool am = false, m = false;
  for (char c :s)
  {
    if (c == '-') am= true;
    else if (isdigit(c))
    {
      cur = cur*10+ (c-'0');
      m = true;
    }
    else
    {
      if (m)
      {
        ans += (am ? -cur : cur);
        cur = 0;
        am = false;
        m = false;
      }
      else am = false;
    }
  }
  if (m) ans += (am ? -cur : cur);
  cout << ans;
  return 0;
}
