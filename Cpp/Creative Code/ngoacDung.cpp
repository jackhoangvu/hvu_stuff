#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;
    int d = 0;
    bool ok = true;
    for (char c : s)
    {
      if (c=='(') d++;
      else d--;
      if (d<0)
      {
        ok = false;
        break;
      }
    }
    if (ok && d==0) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
