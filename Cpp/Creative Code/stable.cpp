#include <bits/stdc++.h>

using namespace std;
int n;
long long ans = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> a1(n), a2(n);
  for (int i = 0; i < n; i++)cin>>a1[i];
  for (int i = 0; i < n; i++)cin>>a2[i];
  unordered_map<int,long long> cnt1, cnt2;
  for (int i = 0; i < n; i++) {
    ans += cnt1[a1[i]];
    cnt1[a1[i]]++;
    ans += cnt2[a2[i]];
    cnt2[a2[i]]++;
  }
  cout << ans;
  return 0;
}
