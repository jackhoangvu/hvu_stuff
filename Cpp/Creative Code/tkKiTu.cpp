#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  vector<int> freq(26, 0);
  for (char c : s) {
    if (c >= 'a' && c <= 'z') {
      freq[c - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << freq[i] << " ";
  }
  return 0;
}
