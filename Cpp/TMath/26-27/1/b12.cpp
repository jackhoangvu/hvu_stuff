#include<bits/stdc++.h>

using namespace std;
const long long INF=1LL<<60;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,d; cin>>n>>k>>d;
  vector<long long> a(n+1),w(k+1);
  vector<vector<long long>> dp(k+1,vector<long long>(n+1,-INF));
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for (int i=1; i<=k; i++){
    cin>>w[i];
  }
  for (int i=1; i<=n; i++){
    dp[1][i]=w[1]*a[i];
  }
  for (int t=2; t<=k; t++){
    for (int i=1; i<=n; i++){
      for (int j=1; j<=i-d; j++){
        if(dp[t-1][j]!=-INF) dp[t][i]=max(dp[t][i],dp[t-1][j]+w[t]*a[i]);
      }
    }
  }
  long long ans=-INF;
  for (int i=1; i<=n; i++){
    ans=max(ans,dp[k][i]);
  }
  if(ans==-INF){
    cout<<-1;
  }
  else{
    cout<<ans;
  }
  return 0;
}
