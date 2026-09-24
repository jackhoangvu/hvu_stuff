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
  for(int i=1; i<=n-2; i++){
    cin>>c[i];
  }
  vector<long long> dp(n+2,0LL);
  dp[1]=a[1];
  // 1-> n
  // 2-> n-1
  // 3-> n-2
  dp[1]=a[1];
  dp[2]=min(a[1]+a[2],b[1]);
  for(int i=3; i<=n; i++){
    dp[i]=min(dp[i-1]+a[i],min(dp[i-2]+b[i-1],dp[i-3]+c[i-2]));
  }
  cout<<dp[n]<<"\n";
  return 0;
}
