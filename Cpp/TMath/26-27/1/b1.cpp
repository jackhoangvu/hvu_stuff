#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
const int mxn=1e6+5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  vector<int> f(mxn);
  f[0]=1;
  for (int i=1; i<=mxn; i++){
    f[i]=(f[i-1]+f[i-2])%mod;
  }
  while(t--){
    int n; cin>>n;
    n--;
    cout<<f[n]<<"\n";
  }
  return 0;
}
