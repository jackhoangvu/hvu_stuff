#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  vector<int> x(n);
  vector<vector<int>> dp(n, vector<int>(m+2,0));
  for (int i=0; i<n; i++){
    cin>>x[i];
  }
  if(x[0]==0){
    for(int v=1; v<=m; v++){
      dp[0][v]=1;
    }
  }
  else{
    dp[0][x[0]]=1;
  }
  int ans=0;
  for (int i=1; i<=n-1; i++){
    for(int v=1; v<=m; v++){
      if(x[i]!=0&&x[i]!=v){
        continue;
      }
      else{
        dp[i][v]=((long long)dp[i-1][v-1]+dp[i-1][v]+dp[i-1][v+1])%MOD;
      }
    }
  }
  for(int v=1; v<=m; v++){
    ans+=dp[n-1][v];
    ans=ans%MOD;
  }
  cout<<ans;
  return 0;
}
