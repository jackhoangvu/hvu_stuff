#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n+1),b(n+1),c(n+1);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  for(int i=1; i<n; i++){
    cin>>b[i];
  }
  for(int i=1; i<n; i++){
    cin>>c[i];
  }
  vector<long long> dp(n+1,0LL);
  dp[1]=a[1];
  for(int i=2; i<=n; i++){
    dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i-1]+c[i-1]);
  }
  cout<<dp[n]<<"\n";
  return 0;
}
