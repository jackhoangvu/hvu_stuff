#include <bits/stdc++.h>
using namespace std;
string x, y;
int n, m;
long long f[2005][205],s[2005][205],ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x>> y;
  n = x.size(), m=y.size();
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      if (x[i]==y[j])
        f[i+1][j+1]= (j==0) ? 1:f[i][j]; //x[i]==y[i]

  for (int i = n - 1; i >= 0; --i)
    for (int j = m - 1; j >= 0; --j)
      if (x[i]== y[j])
        s[i][j] = (j== m-1) ? 1:s[i+1][j+1];
  for (int i=1; i<n; ++i)
    for (int j=1; j<m;  ++j)
      if (f[i][j]){
        for (int t=i; t<n; ++t) ans += s[t][j];
      }
  cout << ans;
  return 0;
}
