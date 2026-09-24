#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int x; cin>>x;
  int mi=x;
  int ans=INT32_MIN;
  vector<int> a(n);
  a[0]=x;
  for(int i=1; i<n; i++){
    cin>>a[i];
    ans=max(ans,a[i]-mi);
    mi=min(mi,a[i]);
  }
  cout<<ans;
  return 0;
}
