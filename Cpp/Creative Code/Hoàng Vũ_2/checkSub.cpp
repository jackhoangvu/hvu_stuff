#include <bits/stdc++.h>
using namespace std;
string s,x;
int n;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>s>>n;
  vector<int> v[26];
  for (int i = 0; i < s.size(); i++){
    v[s[i]-'a'].push_back(i);
  }
  while (n--) {
    cin >> x;
    int cur = -1;
    for (char c : x) {
      // c tiep theo sau cur
      auto it= upper_bound(v[c-'a'].begin(),v[c-'a'].end(),cur);
      if (it == v[c-'a'].end()) {
        cur = -2; break;
      }
      cur = *it;
    }
    cout << (cur != -2) << "\n";
  }
  return 0;
}
