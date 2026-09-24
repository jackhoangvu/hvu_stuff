#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  vector<int> a(n+1), dp(x+1,0);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  dp[0]=1;
  for (int i=1; i<=x; i++){
    for (int j=0; j<n; j++){
      if(i-a[j]>=0)
        dp[i]=(dp[i]+dp[i-a[j]])%MOD;
    }
  }
  cout<<dp[x];
  return 0;
}
