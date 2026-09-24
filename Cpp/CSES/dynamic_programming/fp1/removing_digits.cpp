#include <bits/stdc++.h>

using namespace std;
const int INF=1e7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> dp(n+1,INF);
  dp[0]=0;
  for (int i=1; i<=n; i++){
    int tmp=i;
    while(tmp>0){
      int d=tmp%10;
      if(d>0) dp[i]=min(dp[i],dp[i-d]+1);
      tmp/=10;
    }
  }
  cout<<dp[n]<<"\n";
  return 0;
}
