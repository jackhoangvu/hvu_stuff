#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long ans=LLONG_MIN,cur=0;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
    cur=max(a[i],cur+a[i]);
    ans=max(ans,cur);
  }
  cout<<ans;
  return 0;
}
