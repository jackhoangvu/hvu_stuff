#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
long long inv(long long b, long long m=mod){
  return bp(b,mod-2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long ans=((n-1)%mod)*((n-2)%mod);
  ans%=mod;
  ans=ans*inv(2);
  ans%=mod;
  cout<<ans;
  return 0;
}
