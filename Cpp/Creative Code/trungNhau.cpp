#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  unordered_set<long long> c;
  vector<long long> ans;
  for (int i=0; i<n; i++)
  {
    long long x;
    cin>>x;
    c.insert(x);
  }
  for (int i=0; i<m; i++)
  {
    long long x;
    cin>>x;
    if (c.count(x))
    {
      ans.push_back(x);
      c.erase(x);
    }
  }
  if (ans.empty())
  {
    cout<<0;
    return 0;
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<'\n';
  for (auto x:ans)
  {
    cout<<x<<' ';
  }
  return 0;
}
