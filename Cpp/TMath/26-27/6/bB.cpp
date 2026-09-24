#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<vector<int>> a(m+2,vector<int>(n+2));
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  vector<vector<int>> dp(m+2,vector<int>(n+2,INT_MIN));
  dp[1][1]=a[1][1];
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      if (i==1&&j==1) continue;
      dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
    }
  }
  cout<<dp[m][n];
  return 0;
}
