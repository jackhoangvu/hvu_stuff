#include <bits/stdc++.h>

using namespace std;
int k;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  int ans = 0;
  while (k--) {
    string x;
    cin >> x;
    int cnt[26] = {0};
    bool sp = true;
    for (char c : x) {
      cnt[c - 'a']++;
      if (cnt[c - 'a'] > 2) {
        sp = false;
        break;
      }
    }
    if (sp) ans++;
  }
  cout << ans << '\n';
  return 0;
}
