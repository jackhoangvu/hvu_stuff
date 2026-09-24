#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int m,n,i,j,ans=0;cin>>m>>n;
  vector<vector<int>> a(m+1,vector<int>(n+1)),dp(m+1,vector<int>(n+1));
  for(i=1;i<=m;i++)for(j=1;j<=n;j++)cin>>a[i][j];
  for(i=1;i<=m;i++)for(j=1;j<=n;j++){
    dp[i][j]=1;
    if(a[i][j]==a[i-1][j]&&a[i][j]==a[i][j-1]&&a[i][j]==a[i-1][j-1])
      dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
    ans=max(ans,dp[i][j]);
  }
  cout<<ans;
  return 0;
}
