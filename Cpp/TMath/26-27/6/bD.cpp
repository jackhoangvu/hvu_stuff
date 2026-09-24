#include <bits/stdc++.h>

using namespace std;
const int mod=14062008;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  vector<int> ch(n+1,0);
  for(int i=0; i<k; i++){
    int x;
    cin>>x;
    ch[x]=1;
  }
  vector<int> dp(n+1,0);
  dp[1]=1;
  for(int i=2; i<=n; i++){
    if(ch[i]) dp[i]=0;
    else dp[i]=(dp[i-1]+dp[i-2])%mod;
  }
  cout<<dp[n]%mod;
  return 0;
}
