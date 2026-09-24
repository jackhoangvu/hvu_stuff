#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  long long s=0;
  for(int i=1; i<n; i++){
    for(int j=i+1; j<=n; j++){
      s=s+a[i]*a[j]*(j-i);
    }
  }
  cout<<s%mod;
  return 0;
}
