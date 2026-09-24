#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  unordered_map<long long, int> freq;
  freq.reserve(n * 2);
  freq.max_load_factor(0.7f);

  for (int i = 0; i < n; i++){
    long long x;
    cin >> x;
    freq[x]++;
  }

  if ((int)freq.size() < 2){
    cout << 0;
    return 0;
  }

  int first = 0, second = 0;
  for (auto &p : freq){
    int c = p.second;
    if (c > first){
      second = first;
      first = c;
    }
    else if (c > second){
      second = c;
    }
  }

  cout << second;
  return 0;
}
