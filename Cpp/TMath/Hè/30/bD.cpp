#include <bits/stdc++.h>

using namespace std;
const int mod=1532023;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long m,n; cin>>m>>n;
  long long mo=(m+1)/2,me=m/2;
  long long no=(n+1)/2,ne=n/2;
  long long ans=n%mod*(mo*(mo-1)%mod)%mod*(no%mod)%mod;
  ans=(ans+n%mod*(me*me%mod)%mod*(ne%mod))%mod;
  ans=(ans+no*no%mod*mo%mod+ne*(ne+1)%mod*me%mod)%mod;
  cout<<ans;
  return 0;
}
