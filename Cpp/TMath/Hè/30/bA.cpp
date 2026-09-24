#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int m; cin>>m;
  for (int i=0; i<m; i++){
    long long x; cin>>x;
    cout<<lower_bound(a.begin(),a.end(),x)-a.begin()<<"\n";
  }
  return 0;
}
