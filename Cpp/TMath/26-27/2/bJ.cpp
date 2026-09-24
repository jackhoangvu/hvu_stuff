#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<long long>dp(n+1,0),s(n+1,0);
  dp[0]=1;
  s[0]=1;
  for(int i=1; i<=n; i++){
    long long cur=s[i-1];
    if(i-k-1>=0) cur-=s[i-k-1];
    dp[i]=(cur%mod+mod)%mod;
    s[i]=(s[i-1]+dp[i])%mod;
  }
  cout<<dp[n]<<'\n';
  return 0;
}
