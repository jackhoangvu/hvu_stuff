#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  vector<int> w(n),v(n);
  for (int i=0; i<n; i++){
    cin>>w[i]>>v[i];
  }
  vector<int> dp(m+1);
  for (int i=0; i<n; i++){
    for (int j=m; j>=w[i]; j--){
      dp[j]=max(dp[j],v[i]+dp[j-w[i]]);
    }
  }
  cout<<dp[m];
}
