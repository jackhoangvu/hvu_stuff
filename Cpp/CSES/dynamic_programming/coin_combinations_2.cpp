#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin>>n>>x;
  int a[101];
  vector<int> dp(x+1,0);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  dp[0]=1;
  for (int j=0; j<n; j++){
    for (int i=1; i<=x; i++){
      if(i-a[j]>=0){
        dp[i]=(dp[i]+dp[i-a[j]]) % mod;
      }
    }
  }
  cout<<dp[x];
  return 0;
}
