#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long x, y,a[200005];
  cin>> n>>x>>y;
  for (int i=0; i<n; ++i) cin>> a[i];
  long long a1= a[0]* x;
  long long ans= LLONG_MIN;
  for (int i=1; i<n; ++i) {
    ans = max(ans, a1+ a[i]* y);
    a1 = max(a1, a[i]*x);
  }
  cout<< ans<<'\n';
  return 0;
}
