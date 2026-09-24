#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long dp[22]={0};
  dp[0]=1;
  dp[1]=1;
  for (int i=2; i<=n+1; i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
