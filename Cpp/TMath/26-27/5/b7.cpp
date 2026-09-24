#include <bits/stdc++.h>

using namespace std;
const long long mod=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<string> a(m+2);
  for (int i=1; i<=m; i++){
    cin>>a[i];
  }
  vector<vector<int>> b(m+2,vector<int>(n+2,0));
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      if(a[i][j-1]=='.') b[i][j]=1;
      else b[i][j]=0;
    }
  }
  vector<vector<long long>> dp(m+2,vector<long long>(n+2,0));
  dp[1][1]=1;
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      if(i==1&&j==1) continue;
      if(!b[i][j]) {
        dp[i][j]=0;
        continue;
      }
      if(i==1) dp[i][j]=dp[i][j-1];
      else if (j==1) dp[i][j]=dp[i-1][j];
      else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  cout<<dp[m][n]%mod;
  return 0;
}
