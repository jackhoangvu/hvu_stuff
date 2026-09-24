#include <bits/stdc++.h>

using namespace std;
const long long mxn=1e6;
const long long mod=1e9+7;
long long dp[mxn + 1][2];
void d(){
  dp[1][0]=1;
  dp[1][1]=1;
  for (int i=2; i<=mxn; i++){
    dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%mod;
    dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%mod;
  }
}
void solve(){
  int n; cin>>n;
  long long ans=(dp[n][0]+dp[n][1])%mod;
  cout<<ans<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  d();
  while(t--){
    solve();
  }
  return 0;
}
