#include <bits/stdc++.h>

using namespace std;
const int INF=1e7+5;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  vector<int> a(n+1), b(n+1), dp(x+1, 0);
  //dp[i]= max #of pages at price x
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<n; i++){
    cin>>b[i];
  }
  for (int i=0; i<n; i++){
    for (int j=x; j>=a[i]; j--){
      dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
    }
  }
  cout<<dp[x];
  return 0;
}
