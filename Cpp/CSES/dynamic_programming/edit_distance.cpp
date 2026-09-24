#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string x,y; cin>>x>>y;
  int n=x.length(), m=y.length();
  vector<vector<int>> dp(n+2, vector<int>(m+2,0));
  for(int a=0; a<=n; a++){
    dp[a][0]=a;
  }
  for(int b=0; b<=m; b++){
    dp[0][b]=b;
  }
  for(int a=1; a<=n; a++){
    for(int b=1; b<=m; b++){
      int e=dp[a-1][b-1];
      if(x[a-1]!=y[b-1]) e++;
      dp[a][b]=min(min(dp[a][b-1]+1, dp[a-1][b]+1), e);
    }
  }
  cout<<dp[n][m];
  return 0;
}
