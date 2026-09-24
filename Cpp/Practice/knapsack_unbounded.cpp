#include <bits/stdc++.h>

using namespace std;
const int INF=1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // srand(time(0));

  int n,m; cin>>n>>m;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  vector<int> dp(m+5,INF);
  dp[0]=0;
  for (int i=0; i<n; i++){
    for (int j=a[i]; j<=m; j++){
      if(dp[j-a[i]]!=INF){
        dp[j]=min(dp[j],dp[j-a[i]]+1);
      }
    }
  }
  if(dp[m]>=INF){
    cout<<-1;
    // else cout<<1000000<<"\n";
  }
  else cout<<dp[m];
  return 0;
}
