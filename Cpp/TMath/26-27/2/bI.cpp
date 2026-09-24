#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> dp(n+1,0);
  dp[0]=1;
  for(int i=1; i<=n; i++){
    for(int j=max(i-k,0); j<i; j++){
      dp[i]=(dp[i]+dp[j])%mod;
    }
  }
  cout<<dp[n];
  return 0;
}
