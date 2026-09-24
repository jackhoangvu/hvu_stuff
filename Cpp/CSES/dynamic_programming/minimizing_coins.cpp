#include <bits/stdc++.h>

using namespace std;
const int INF=1e7+5;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  vector<int> a(n+1), dp(x+1, INF);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  dp[0]=0;
  for (int i=1; i<=x; i++){
    for (int j=0; j<n; j++){
      if(i-a[j]>=0){
        dp[i]=min(dp[i],dp[i-a[j]]+1);
      }
    }
  }
  if(dp[x]!=INF) cout<<dp[x];
  else cout<<"-1";
  return 0;
}
