#include <bits/stdc++.h>

using namespace std;
const int mx=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> dp(n+2,0);
  dp[0]=1;
  for (int i=1; i<=n; i++){
    for (int j=1; j<=6; j++){
      if(i-j>=0) dp[i]=(dp[i]+dp[i-j])%mx;
    }
  }
  cout<<dp[n];
  return 0;
}
