#include <bits/stdc++.h>

using namespace std;
// const int mod=1e9+7;
const int mxn=92;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  vector<unsigned long long> f(mxn+1);
  f[0]=1;
  f[1]=1;
  for (int i=2; i<=mxn; i++){
    f[i]=f[i-1]+f[i-2];
  }
  while(t--){
    int n; cin>>n;
    // n--;
    cout<<f[n]<<"\n";
  }
  return 0;
}
