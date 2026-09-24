#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long ans=LLONG_MIN;
  long long dp1=LLONG_MIN;
  long long dp2=LLONG_MIN;
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
    if(dp2!=LLONG_MIN) ans=max(ans,dp2-a[i]);
    if(dp1!=LLONG_MIN) dp2=max(dp2,dp1+a[i]);
    dp1=max(dp1,a[i]);
  }
  cout<<ans;
  return 0;
}
