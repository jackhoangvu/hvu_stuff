#include <bits/stdc++.h>

using namespace std;
const int INF=1e9;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i,j; cin>>i>>j;
  vector<vector<int>> dp(i+1, vector<int>(j+1,INF));
  for (int w=1; w<=i; w++){
    for (int h=1; h<=j; h++){
      if(w==h) {dp[w][h]=0; continue;}
      for(int k=1; k<w; k++){
        dp[w][h]=min(dp[w][h],dp[k][h]+dp[w-k][h]+1);
      }
      for(int k=1; k<h; k++){
        dp[w][h]=min(dp[w][h],dp[w][k]+dp[w][h-k]+1);
      }
    }
  }
  cout<<dp[i][j]<<"\n";
  return 0;
}
