#include <bits/stdc++.h>

using namespace std;
bool nt(long long n) {
  if (n < 2) return false;
  for (int i = 2; i*i <= n; i++) {
    if (n % i ==0) return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int dem=0;
  long long ans=0;
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      dem++;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      string cur = "";
      while (i < s.size() &&isdigit(s[i])) {
        cur+= s[i];
        i++;
      }
      while (cur.size()>1 && cur[0] == '0') {
        cur.erase(cur.begin());
      }
      long long x = stoll(cur);
      if (nt(x)) {
        ans = max(ans, x);
      }
    }
  }
  cout << dem << "\n";
  cout << ans;
  return 0;
}
