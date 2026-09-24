#include <bits/stdc++.h>

using namespace std;
const int INF=1e8+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> dp(n+1,INF);
  dp[0]=0;
  for (int i=1; i<=n; i++){
    for(char d:to_string(i)){
      if((d-'0')>=0) dp[i]=min(dp[i], dp[i-(d-'0')]+1);
    }
  }
  cout<<dp[n];
  return 0;
}
