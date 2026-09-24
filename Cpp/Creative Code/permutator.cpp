#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0,b[100005],c[100004];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=0; i<n; ++i)
  {
    long long a;
    cin >> a;
    c[i] = a*1LL * (i+1) * (n-i);//0->i, i->n-1
  }
  for (int i=0; i<n; ++i) cin >> b[i];
  sort(c,c+n); sort(b,b+n,greater<long long>());
  for (int i=0; i<n; ++i) ans += c[i]*b[i];
  cout << ans;
  return 0;
}
