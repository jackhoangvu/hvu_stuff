#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans=-1;
  int n; cin>>n;
  vector<long long> a(n+1);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  long long ma=a[n];
  for (int i=n-1; i>=1; i--){
    ans=max(ans,a[i]-ma);
    ma=min(ma,a[i]);
  }
  if(ans==0) ans=-1;
  cout<<ans;
  return 0;
}
