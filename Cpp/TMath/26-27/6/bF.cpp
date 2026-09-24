#include<bits/stdc++.h>
using namespace std;
static const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<int> b(m+1);
  for(int i=1; i<=m; i++){
    cin>>b[i];
  }
  vector<int> dp(n+1,0);
  dp[1]=1;
  for(int s=2; s<=n; s++){
    for(int j=1; j<=m; j++){
      if(s>=b[j]){
        dp[s]=(dp[s]+dp[s-b[j]])%mod;
      }
    }
  }
  cout<<dp[n];
  return 0;
}
