#include <bits/stdc++.h>
using namespace std;
long long a[2005],b[2005];
long long minA[2005],  minB[2005];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m,ans=0; long long S;
  cin>> n >>m >>S;
  fill(minA+1, minA+n+1, 1e18);
  for (int i=1; i<=n; ++i) cin>> a[i];
  for (int i =1; i<= m; ++i) cin>> b[i];
  for (int i=1; i<=n; ++i) {
    long long sum= 0;
    for (int j=i; j<=n; ++j) {
      sum += a[j];
      minA[j-i+ 1] = min(minA[j-i +1], sum);
    }
  }
  fill(minB+1, minB+m +1, 1e18);
  for (int i=1; i<=m; ++i) {
    long long sum =0;
    for (int j=i; j<=m; ++j) {
      sum+= b[j];
      minB[j-i+ 1] = min(minB[j-i+1], sum);
    }
  }
  for (int H=1; H<=n; ++H) {
    for (int W=1; W<=m; ++W) {
      if (minA[H]<= S/ minB[W]) {
        ans = max(ans, H*W);
      }
    }
  }
  cout<< ans;
  return 0;
}
