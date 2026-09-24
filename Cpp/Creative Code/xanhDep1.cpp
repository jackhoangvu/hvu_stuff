#include <bits/stdc++.h>
using namespace std;
char x;
string s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x;
  cin >> s;
  int cnt = 0;
  for (char c : s)
    if (c != x) cnt++;
  cout << cnt;
  return 0;
}
