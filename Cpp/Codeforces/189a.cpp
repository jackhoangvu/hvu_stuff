#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  int val[]={a,b,c};
  vector<int> dp(n+1,0);
  dp[0]=1;
  for (int i=1; i<=n; i++){
    for(int v:val){
      if(i-v>=0) dp[i]=max(dp[i],dp[i-v]+1);
      cout<<dp[i]<<" "<<dp[i-v]<<"\n";
    }
  }
  cout<<dp[n-1];
  return 0;
}
