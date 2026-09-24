#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<pair<long long, long long>> ans;
  for (long long x = 1; x * x <= n; x++)
  {
    if (n % x == 0)
    {
      long long y=n/x;
      if (__gcd(x,y)==1) ans.push_back(std::make_pair(x,y));
    }
  }
  cout<<ans.size()<<'\n';
  for (auto &p:ans) cout<<p.first<<" "<<p.second<<'\n';
  return 0;
}
