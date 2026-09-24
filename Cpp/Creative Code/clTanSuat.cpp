#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int diff(int freq[]){
  int u = 1e9, v = 0;
  for (int c =0; c<26;c++) {
    if (freq[c] > 0) {
      u = min(u, freq[c]);
      v = max(v, freq[c]);
    }
  }
  return v - u;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> k;
  int freq[26] = {0};
  for (int i =0; i < k; i++) {
    freq[s[i] - 'a']++;
  }
  int max = diff(freq);
  int cnt = 1;
  //cua so truot
  for (int i =k; i<s.length();i++) {
    int rem = s[i-k];
    int add = s[i];
    freq[rem - 'a']--;
    freq[add - 'a']++;
    int cur = diff(freq);
    if (cur > max) {
      max = cur;
      cnt = 1;
    } else if (cur == max) {
      cnt++;
    }
  }
  cout << max << "\n" << cnt << '\n';
  return 0;
}
