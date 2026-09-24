#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  vector<int> a(n+1);
  for (int i=1; i<=n; ++i) cin>>a[i];
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin>>l>>r;
    int mn = a[l], mx = a[l];
    for (int i = l+1; i <= r; i++) {
      mn = min(mn,a[i]);
      mx = max(mx,a[i]);
    }
    cout<<(long long)mn*mx<<"\n";
  }
}
