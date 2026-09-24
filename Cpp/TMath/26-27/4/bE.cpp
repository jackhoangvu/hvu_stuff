#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<long long> a(n+1);
  vector<long long> dp(n+1,0);
  for (int i=1; i<=n; i++) {
    cin>>a[i];
    dp[i]=max(dp[i-1],(i>=2?dp[i-2]:0LL)+a[i]);
  }
  cout<<dp[n];
  return 0;
}
