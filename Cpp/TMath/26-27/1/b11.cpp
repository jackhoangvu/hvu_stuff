#include<bits/stdc++.h>

using namespace std;
const long long INF=1LL<<60;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int k;
  cin>>n>>k;
  // vector<long long> w;
  // w.push_back(0);
  // for (int i=0; i<k; i++){
  //   long long x; cin>>x;
  //   w.push_back(x);
  // }
  vector<long long> a(n+1), w(k+1);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for (int i=1; i<=k; i++){
    cin>>w[i];
  }
  vector<long long> dp(k+1,-INF);
  dp[0]=0;
  for(int i=1; i<=n; i++){
    for(int j=min(i,k); j>=1; j--){
      if(dp[j-1]!=-INF){
        dp[j]=max(dp[j],dp[j-1]+w[j]*a[i]);
      }
    }
  }
  cout<<dp[k];
  return 0;
}
