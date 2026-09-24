#include <bits/stdc++.h>
using namespace std;
string st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> st;
  long long ans=0,cur=0;
  bool num= false;
  for (char c:st)
  {
    if (isdigit(c))
    {
      num = true;
      cur = cur*10 + (c - '0');
    }
    else
    {
      if (num)
      {
        ans = max(ans, cur);
        cur = 0;
        num = false;
      }
    }
  }
  if (num) ans = max(ans, cur);
  cout << ans;
  return 0;
}
