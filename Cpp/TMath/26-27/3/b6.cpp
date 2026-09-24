#include<bits/stdc++.h>

using namespace std;
const long long mxn=4e18;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n+1),b(n+1),c(n+1);
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  for(int i=1; i<n; i++){
    cin>>b[i];
  }
  for(int i=1; i<=n-1; i++){
    cin>>c[i];
  }
  vector<long long> dp(n+2,0LL);
  dp[1]=a[1];
  if(n>=2){
    long long v=c[1]==1?mxn:b[1];
    dp[2]=min(1LL*a[1]+a[2],v);
  }
  for(int i=3; i<=n; i++){
    long long x=c[i-1]==1?mxn:b[i-1];
    dp[i]=min(dp[i-1]+a[i],dp[i-2]+x);
  }
  cout<<dp[n]<<"\n";
  return 0;
}
