#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a[1000005], m=0;
  cin >> n;
  for(int i=0; i<=n; ++i)
    cin >> a[i];
  for (int i=1; i<n; ++i) {
    m = __gcd(m, abs(a[i] - a[i- 1]));
  }
  cout << m << "\n";
  return 0;
}
