#include <bits/stdc++.h>

using namespace std;
int n,p,q; long long s[1000005], ans=-4e18;deque<int>d;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>p>>q;
  for (int i = 1; i <= n; i++) {
    long long x; cin>>x;
    s[i] = s[i-1] + x;
  }
  for (int r = p; r <= n; r++) {
    int l = r-p;
    while (!d.empty() && s[d.back()] >= s[l])
      d.pop_back();
    d.push_back(l);
    while (!d.empty() && d.front() < r - q)
      d.pop_front();
    ans = max(ans, s[r] - s[d.front()]);
  }
  cout << ans;
  return 0;
}
