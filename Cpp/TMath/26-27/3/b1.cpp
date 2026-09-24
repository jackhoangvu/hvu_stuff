#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n+2);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  vector<long long> dp(n+2,0);
  dp[0]=0;
  dp[1]=a[1];
  for(int i=2; i<=n; i++){
    dp[i]=a[i]+min(dp[i-1],dp[i-2]);
  }
  cout<<dp[n];
  return 0;
}
