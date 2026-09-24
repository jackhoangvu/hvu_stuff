#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<string> s(n+1);
  for (int i=0; i<n; i++){
    cin>>s[i];
  }
  if(s[0][0]=='*'){cout<<0<<"\n"; return 0;}
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  dp[0][0]=1;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if(s[i][j]=='*'){dp[i][j]=0; continue;}
      if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
      if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
    }
  }
  cout<<dp[n-1][n-1];
  return 0;
}
