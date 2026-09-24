#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> dp(n+1,0);
  dp[0]=1;
  for (int i=1; i<n+1; i++){
    for (int s=1; s<7; s++){
      if(i-s>=0) dp[i]=(dp[i]+dp[i-s])%MOD;
    }
  }
  cout<<dp[n];
  return 0;
}
