#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  n%=mod;
  cout<<2*n%mod*n%mod*n%mod;
  return 0;
}
