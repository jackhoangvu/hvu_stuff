#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("CAU2.INP", "r", stdin);
  // freopen("CAU2.OUT", "w", stdout);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long ans=0;
  sort(a.begin(), a.end());
  long long t=0;
  //0, 1, 1+3
  // 0 1 3
  for (int i=0; i<n-1; i++){
    t+=a[i];
    ans+=t;
  }
  cout<<ans<<"\n";
  return 0;
}
