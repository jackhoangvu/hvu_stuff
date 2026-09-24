#include <bits/stdc++.h>

using namespace std;
const int mod=998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  set<int> s;
  for (int i=0; i<k; i++){
    int l,r; cin>>l>>r;
    s.insert(l);
    s.insert(r);
  }
  // for (auto& x:s) cout<<x<<" ";
  vector<long long> dp(n+1,0);
  dp[1]=1;
  for (int i=2; i<=n; i++){
    for (auto& j:s){
      if(i-j>0) dp[i]=(dp[i]+dp[i-j])%mod;
    }
  }
  cout<<dp[n];
  return 0;
}
