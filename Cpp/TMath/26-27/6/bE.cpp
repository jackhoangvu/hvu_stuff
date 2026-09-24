#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<long long> h(n+2);
  for (int i=0; i<n; i++){
    cin>>h[i];
  }
  vector<long long> dp(n+2,0);
  dp[0]=0;
  dp[1]=llabs(h[0]-h[1]);
  for(int i=2; i<n; i++){
    dp[i]=min(dp[i-1]+llabs(h[i-1]-h[i]),dp[i-2]+3*llabs(h[i-2]-h[i]));
  }
  cout<<dp[n-1]<<"\n";
  return 0;
}
