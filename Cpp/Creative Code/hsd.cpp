#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  int d = 0;
  for (int i = 0; i < m - 1; i++)
  {
    d = max(d, a[i+1]- a[i] - 1);
  }
  d = max(d, n - a[m-1]);
  cout<<d;
  return 0;
}
