#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> f(n+1);
  f[1]=f[2]=1;
  for(int i=3; i<=n;i ++){
    f[i]=(f[i-1]+f[i-2])%mod;
  }
  cout<<f[n]%mod<<"\n";
  return 0;
}
