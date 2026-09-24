#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s,t; cin>>s>>t;
  int n=s.length(),m=t.length();
  vector<vector<int>> dp(n+3,vector<int>(m+3,0));
  dp[0][0]=0;
  int ans=0;
  for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        ans=max(ans,dp[i][j]);
      }
    }
  }
  cout<<ans;
  return 0;
}
